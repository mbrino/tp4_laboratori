#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"


int  initialiceArrayUsuario(EUsuario lista[], int length)
{
    int i;
    if(lista!=NULL && length>0)
    {
       for(i=0; i<length; i++)
        {
            lista[i].estado=1;
        }
        return 0;
    }
    return -1;
}

int  initialiceArrayComment(EComment lista[], int length)
{
    int i;
    if(lista!=NULL && length>0)
    {
       for(i=0; i<length; i++)
        {
            lista[i].estado=1;
        }
        return 0;
    }
    return -1;
}

EUsuario* findByNick(ArrayList* pList, char nickName[])
{
    EUsuario* eUser = NULL;
    int i;

    if(pList->isEmpty(pList)==0)
    {
        for(i=0; i<pList->size; i++)
        {
            eUser = pList->get(pList, i);
            printf("Nickname; %s", eUser->nickName);
            if(strcmp(eUser->nickName, nickName)==0)
            {
                return eUser;
            }
        }
        eUser=NULL;
    }
    return eUser;
}

int newUser(ArrayList* pList, EUsuario* eUser)
{
    int returnValue=-1;

    if(findByNick(pList, eUser->nickName)==NULL)
    {
        returnValue=pList->add(pList, eUser);
    }else
    {
        printf("El nick ya existe\n");
    }

    return returnValue;
}

int modifUser(ArrayList* pList, void* pElement, void* pElementCpy)
{
    int index;

    index = pList->indexOf(pList, pElement);
    if(index>=0)
    {
        if(pList->set(pList, index, pElementCpy)==0)
        {
            return 0;
        }
    }

    return -1;
}

int deleteUser(ArrayList* pList, void* pElement)
{
    int index;
    int remove;

    index = pList->indexOf(pList, pElement);

    if(index>=0)
    {
        remove = pList->remove(pList, index);
        if(remove==0)
        {
            printf("Se elemino exitosamente el usuario\n");
            return 0;
        }
        printf("No se pudo eliminar el usuario\n");
    }
    return -1;
}

EComment* newComment(ArrayList* pList, char nickName[], char comment[])
{
    EComment* pComment = NULL;
    if(pList!=NULL)
    {
        pComment = (EComment*)malloc(sizeof(EComment));
        printf("113\n");
        pComment->idComment = newIdComment(pList);
        strcpy(pComment->nickName, nickName);
        strcpy(pComment->comment, comment);
        pComment->like = 0;
        if(pList->push(pList, 0, pComment)==0)
        {
            printf("120\n");
            return pList->get(pList, 0);
        }else
        {
            return NULL;
        }
    }
    return pComment;
}

int newLike(ArrayList* pList, int idComment)
{
    int i;
    EComment* pComment;

    if(pList!=NULL)
    {
        for(i=0; i<pList->len(pList); i++)
        {
            pComment = pList->get(pList, i);
            if(pComment->idComment == idComment)
            {
                pComment->like=pComment->like+1;
                return 0;
            }
        }
    }
    return -1;
}

int getNick(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[2000];
    int auxLenght;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%s",aux);
        auxLenght=strlen(aux);
        if(auxLenght>=lowLimit && auxLenght<=hiLimit)
        {
            strcpy(input, aux);
            return 0;
        }
        printf(eMessage);
        printf("Desea volver a ingresar el valor (s/n)");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return -1;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[2000];
    int auxLenght;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%s",aux);
        auxLenght=strlen(aux);
        if(auxLenght>=lowLimit && auxLenght<=hiLimit)
        {
            strcpy(input, aux);
            return 0;
        }
        printf(eMessage);
        printf("Desea volver a ingresar el valor (s/n)");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return -1;
}

int getMail(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[2000];
    int auxLenght;
    char arroba='@';
    char *existeArroba;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%s",aux);
        auxLenght=strlen(aux);
        existeArroba=strchr(aux, arroba);
        if(auxLenght>lowLimit && auxLenght<hiLimit && existeArroba!=NULL)
        {
            strcpy(input, aux);
            return 0;
        }
        printf(eMessage);
        printf("Desea volver a ingresar el valor (s/n)");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return -1;
}

int getIdComment(int* input,char message[],char eMessage[], int lowLimit)
{
    int aux;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%d", &aux);
        if(aux>=lowLimit)
        {
            *input=aux;
            return 0;
        }

        printf(eMessage);
        printf("Desea volver a ingresar el valor (s/n)");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return -1;
}

void informes(EUsuario listaUsu[], int lengthUsu, EComment listaComment[], int lengthComm)
{
    int i;
    int j;
    EUsuario usuario;
    int cantComment=0;
    int acumCom=0;
    int acumLikes=0;
    int acumComUsu=0;
    int maxLikes=0;
    EComment comentario;
    int likesPromedio;

    for(i=0; i<lengthUsu; i++)
    {
        for(j=0; j<lengthComm; j++)
        {
            if(listaUsu[i].estado!=0 ||listaComment[j].estado!=0)
            {
                continue;
            }
            if(strcmp(listaUsu[i].nickName, listaComment[j].nickName)==0)
            {
                acumComUsu=acumComUsu+1;
            }
            if(listaComment[j].like>maxLikes)
            {
                comentario=listaComment[j];
                maxLikes=listaComment[j].like;
            }

            acumLikes=acumLikes+listaComment[j].like;
            acumCom=acumCom+1;
        }

        if(acumComUsu>=cantComment)
        {
            usuario=listaUsu[i];
            cantComment=acumComUsu;
        }
        likesPromedio=acumLikes/acumCom;
    }

    printf("1- El usuario con mas cantidad de comentarios es: %s", usuario.name);
    printf("2- El comentario con mayor cantidad de likes es: %s", comentario.comment);
    printf("3- El valor promedio de likes es: %d", likesPromedio);

}

int newIdComment(ArrayList* pList)
{
    int returnAux = -1;
    EComment* pComment;

    if(pList!=NULL)
    {
        if(pList->size==0)
        {
            returnAux = 0;
        }else
        {
            pComment = pList->get(pList, 0);
            if(pComment!=NULL)
            {
                returnAux = pComment->idComment+1;
            }
        }

    }

    return returnAux;
}

int readFromFileUser(ArrayList* pList, char nombre[])
{
    int returnAux = -1;
    FILE* pFile;
    EUsuario* eUsuario=malloc(sizeof(EUsuario));

    if(pList!=NULL)
    {
        pFile = fopen(nombre, "rb");
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                if(fread(eUsuario, sizeof(EUsuario), 1, pFile)!=1)
                {
                    printf("Final del archivo\n");
                    break;
                }else
                {
                    printf("350\n");
                    pList->add(pList, eUsuario);
                }

            }
            returnAux = 0;
        }
    }
    fclose(pFile);
    return returnAux;
}

int copyToFileUser(ArrayList* pList, char nombre[])
{
    int i;
    int returnAux = -1;
    FILE* pFile;
    EUsuario* eUsuario=NULL;

    if(pList!=NULL)
    {
        pFile = fopen(nombre, "wb");
        if(pFile!=NULL)
        {
            for(i=0; i<pList->len(pList); i++)
            {
                eUsuario = pList->get(pList, i);
                fwrite(eUsuario, sizeof(EUsuario), 1, pFile);
            }
            returnAux = 0;
        }
    }
    fclose(pFile);
    return returnAux;
}

int readFromFileComment(ArrayList* pList, char nombre[])
{
    int returnAux = -1;
    FILE* pFile;
    EComment* pComment=malloc(sizeof(EComment));

    if(pList!=NULL)
    {
        pFile = fopen(nombre, "rb");
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                if(fread(pComment, sizeof(EComment), 1, pFile)!=1)
                {
                    printf("Final del archivo\n");
                    break;
                }else
                {
                    printf("350\n");
                    pList->add(pList, pComment);
                }

            }
            returnAux = 0;
        }
    }
    fclose(pFile);
    return returnAux;
}

int copyToFileComment(ArrayList* pList, char nombre[])
{
    int i;
    int returnAux = -1;
    FILE* pFile;
    EComment* pComment=NULL;

    if(pList!=NULL)
    {
        pFile = fopen(nombre, "wb");
        if(pFile!=NULL)
        {
            for(i=0; i<pList->len(pList); i++)
            {
                pComment = pList->get(pList, i);
                fwrite(pComment, sizeof(EComment), 1, pFile);
            }
            returnAux = 0;
        }
    }
    fclose(pFile);
    return returnAux;
}
