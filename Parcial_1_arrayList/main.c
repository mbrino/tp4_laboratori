#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "ArrayList.h"

int main()
{
    char seguir='s';
    int opcion=0;
    char nickName[31];
    char name[31];
    char mail[51];
    char password[21];
    char comment[201];
    int idComment;

    EUsuario* eUser=NULL;
    EUsuario* eUser2;
    EUsuario *usuarioAux;

    ArrayList* eUserList;
    EUsuario listaUsuarios[MAXUS];

    ArrayList* eCommentList;
    EComment listaComments[MAXUS];

    eUserList=al_newArrayList();
    initialiceArrayUsuario(listaUsuarios, MAXUS);

    eCommentList=al_newArrayList();
    initialiceArrayComment(listaComments, MAXUS);

    eUser2=(EUsuario*)malloc(sizeof(EUsuario));
    strcpy(eUser2->nickName,"Maty");
    strcpy(eUser2->name, "mat");
    strcpy(eUser2->password, "12345");
    strcpy(eUser2->mail, "mat@mat");
    eUserList->add(eUserList, eUser2);
    free(eUser2);

    while(seguir=='s')
    {
        system("cls");
        printf("*****************************************\n*                                       *\n");
        printf("* 1- Agregar usuario                    *\n");
        printf("* 2- Modifcar informacion del usuario   *\n");
        printf("* 3- Eliminar usuario                   *\n");
        printf("* 4- Crear nuevo comentario             *\n");
        printf("* 5- Agregar LIKE                       *\n");
        printf("* 6- Informar                           *\n");
        printf("* 7- Listar                             *\n");
        printf("* 8- Salir                              *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                eUser=(EUsuario*)malloc(sizeof(EUsuario));
                if(getNick(eUser->nickName, "Ingrese un nick\n", "El nick debe tener como minimo 2 caracteres y como maximo 30\n", 2, 30)==0 && getString(eUser->password, "Ingrese un password\n", "El password debe ser mayor a 8 digitos y menor a 20", 5, 20)==0)
                {
                    getString(eUser->name, "Ingrese un nombre\n", "El nombre debe tener como minimo 2 caracteres y como maximo 30\n", 2, 30);
                    getMail(eUser->mail, "Ingrese un mail", "El mail debe contener @\n", 3, 50);

                    if(newUser(eUserList, eUser)!=0)
                    {
                        printf("EL usuario no fue dado de alta\n");
                    }else
                    {
                        printf("El usuario fue dado de alta exitosamente\n");
                    }
                }

                free(eUser);
                system("pause");
                break;
            case 2:

                if(getNick(nickName, "Ingrese el nick del usuario que quiere actualizar\n", "El nick ingresado no es valido\n", 2, 30)==0)
                {
                    eUser=findByNick(eUserList, nickName);
                    eUser2=eUserList->pElements[0];
                    printf("Valor del nick encontrado: %s\n", eUser->nickName);
                    printf("Valor del nick 2 encontrado: %s\n", eUser2->nickName);
                    if(eUser!=NULL)
                    {
                        getString(eUser->name, "Ingrese un nombre\n", "El nombre debe tener como minimo 2 caracteres y como maximo 30\n", 2, 30);
                        getMail(eUser->mail, "Ingrese un mail", "El mail debe contener @\n", 3, 50);
                        getString(eUser->password, "Ingrese un password\n", "El password debe ser mayor a 8 digitos y menor a 20\n", 5, 20);

                    }else
                    {
                        printf("No existe el nick ingresado\n");
                    }

                }

                free(eUser);
                system("pause");
                break;
            case 3:
                getNick(nickName, "Ingrese el nick del usuario que quiere actualizar\n", "El nick ingresado no es valido\n", 2, 30);
                if(findByNick(eUserList,  nickName)!=NULL)
                {

                    if(deleteUser(listaUsuarios, MAXUS, nickName)!=0)
                    {
                        printf("La baja no se pudo realizar, ah ocurrido un error inesperado\n");
                    }else
                    {
                        printf("La baja fue exitosa\n");
                    }
                }else
                {
                    printf("No existe el nick ingresado\n");
                }

                system("pause");
                break;
            case 4:
                getNick(nickName, "Ingrese el nick del usuario que quiere actualizar\n", "El nick ingresado no es valido\n", 2, 30);
                usuarioAux=findByNick(eUserList,  nickName);
                if(usuarioAux!=NULL)
                {
                    getString(password, "Ingrese un password\n", "El password debe ser mayor a 8 digitos y menor a 20", 5, 20);
                    if(strcmp(password, usuarioAux->password)==0)
                    {
                        getString(comment, "Ingrese comentario\n", "El comentario no puede contener mas de 200 caracteres", 1, 200);
                        newComment(listaComments, MAXUS, nickName, comment);
                    }else
                    {
                        printf("Contraseña incorrecta\n");
                    }
                }
                system("pause");
                break;
            case 5:
                getNick(nickName, "Ingrese el nick del usuario que quiere actualizar\n", "El nick ingresado no es valido\n", 2, 30);
                usuarioAux=findByNick(eUserList,  nickName);
                if(usuarioAux!=NULL)
                {
                    getString(password, "Ingrese un password\n", "El password debe ser mayor a 8 digitos y menor a 20", 5, 20);
                    if(strcmp(password, usuarioAux->password)==0)
                    {
                        getIdComment(&idComment, "Ingrese comentario\n", "El comentario no puede contener mas de 200 caracteres", 1, 200);
                        newLike(listaComments, MAXUS, nickName, idComment);
                    }else
                    {
                        printf("Contraseña incorrecta\n");
                    }
                }
                system("pause");
                break;
            case 6:

                system("pause");
                break;
            case 7:

                system("pause");
                break;
            case 8:
                seguir='n';
                break;
        }
    }
    free(eUserList);

    return 0;
}
