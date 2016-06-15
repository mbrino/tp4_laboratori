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
            if(strcmp(eUser->nickName, &nickName[0])==0)
            {
                return eUser;
                break;
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

int modifUser(EUsuario lista[], int length, char nickName[], char name[], char mail[], char password[])
{
    int i;

    if(lista!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if(strcmp(lista[i].nickName, nickName)==0)
            {
                strcpy(lista[i].name,name);
                strcpy(lista[i].mail,mail);
                strcpy(lista[i].password,password);
                return 0;
            }
        }
    }
    return -1;
}

int deleteUser(EUsuario lista[], int length, char nickName[])
{
    int i;
    if(lista!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if(strcmp(lista[i].nickName, nickName)==0)
            {
                lista[i].estado=1;
                return 0;
            }
        }
        printf("No se encontro el usuario\n");
    }
    return -1;
}

int newComment(EComment lista[], int length, char nickName[], char comment[])
{
    int i;
    if(lista!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
          if(lista[i].estado==1)
           {
               lista[i].idComment=i+1;
               strcpy(lista[i].nickName,nickName);
               strcpy(lista[i].comment,comment);
               lista[i].like=0;
               lista[i].estado=0;
               printf("El identidicador de su comentario es %d\n", lista[i].idComment);
               return 0;
           }
        }
        printf("Ah llegado al maximo de comentarios\n");
    }
    return -1;
}

int newLike(EComment lista[], int length, char nickName[], int idComment)
{
    int i;
    if(lista!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if(lista[i].idComment==idComment && strcmp(lista[i].nickName, nickName)==0)
            {
                lista[i].like=lista[i].like+1;
                return 0;
            }
        }
        printf("No se encontro el comentario con identificador %d creado por el alias %s", idComment, nickName);
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

int getIdComment(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%d", &aux);
        if(aux>=lowLimit && aux<=hiLimit)
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
