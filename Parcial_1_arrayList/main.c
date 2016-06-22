#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "ArrayList.h"

#define USERS "users.dat"
#define COMMENTS "comments.dat"

int main()
{
    char seguir='s';
    int opcion=0;
    char nickName[31];
    char password[21];
    char comment[201]={""};
    int idComment;

    EUsuario* eUser=NULL;
    EUsuario* eUser2;
    EUsuario *usuarioAux;

    EComment* pComment;

    ArrayList* eUserList;
    EUsuario listaUsuarios[MAXUS];

    ArrayList* eCommentList;
    EComment listaComments[MAXUS];

    eUserList=al_newArrayList();
    initialiceArrayUsuario(listaUsuarios, MAXUS);

    eCommentList=al_newArrayList();
    initialiceArrayComment(listaComments, MAXUS);

    readFromFileUser(eUserList, USERS);
    readFromFileComment(eCommentList, COMMENTS);
    //readFromFile(eCommentList, COMMENTS);

    eUser2=(EUsuario*)malloc(sizeof(EUsuario));
    strcpy(eUser2->nickName,"Maty");
    //printf("%s", eUser2->nickName);
    strcpy(eUser2->name, "mat");
    strcpy(eUser2->password, "12345");
    strcpy(eUser2->mail, "mat@mat");
    //eUserList->add(eUserList, eUser2);

    while(seguir=='s')
    {
        system("cls");
        printf("*****************************************\n*                                       *\n");
        printf("* 1- Agregar usuario                    *\n");
        printf("* 2- Modifcar informacion del usuario   *\n");
        printf("* 3- Eliminar usuario                   *\n");
        printf("* 4- Crear nuevo comentario             *\n");
        printf("* 5- Agregar LIKE                       *\n");
        //printf("* 6- Informar                           *\n");
        //printf("* 7- Listar                             *\n");
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
                copyToFileUser(eUserList, USERS);
                system("pause");
                break;
            case 2:

                usuarioAux=(EUsuario*)malloc(sizeof(EUsuario));
                if(getNick(usuarioAux->nickName, "Ingrese el nick del usuario que quiere actualizar\n", "El nick ingresado no es valido\n", 2, 30)==0)
                {
                    eUser=findByNick(eUserList, usuarioAux->nickName);
                    if(eUser!=NULL)
                    {
                        getString(usuarioAux->name, "Ingrese un nombre\n", "El nombre debe tener como minimo 2 caracteres y como maximo 30\n", 2, 30);
                        getMail(usuarioAux->mail, "Ingrese un mail", "El mail debe contener @\n", 3, 50);
                        getString(usuarioAux->password, "Ingrese un password\n", "El password debe ser mayor a 8 digitos y menor a 20\n", 5, 20);
                        modifUser(eUserList, eUser, usuarioAux);
                        printf("Se actualizó el registro\n");

                    }else
                    {
                        printf("No existe el nick ingresado\n");
                    }

                }
                copyToFileUser(eUserList, USERS);
                system("pause");
                break;
            case 3:

                getNick(nickName, "Ingrese el nick del usuario que quiere eliminar\n", "El nick ingresado no es valido\n", 2, 30);
                eUser = findByNick(eUserList,  nickName);
                if(eUser!=NULL)
                {
                    deleteUser(eUserList, eUser);
                }else
                {
                    printf("No existe el nick ingresado\n");
                }

                copyToFileUser(eUserList, USERS);
                system("pause");
                break;
            case 4:
                getNick(nickName, "Ingrese el nick del usuario que quiere actualizar\n", "El nick ingresado no es valido\n", 2, 30);
                eUser=findByNick(eUserList,  nickName);
                if(eUser!=NULL)
                {
                    getString(password, "Ingrese un password\n", "El password debe ser mayor a 8 digitos y menor a 20", 5, 20);
                    if(strcmp(password, eUser->password)==0)
                    {
                        getString(comment, "Ingrese comentario\n", "El comentario no puede contener mas de 200 caracteres", 1, 200);
                        pComment = newComment(eCommentList, nickName, comment);
                        if(pComment!=NULL)
                        {
                            printf("El comentario fue dado de alta con el id: %d\n", pComment->idComment);
                        }else
                        {
                            printf("No se pudo dar de alta el comentario\n");
                        }
                    }else
                    {
                        printf("Contraseña incorrecta\n");
                    }
                }else
                {
                    printf("No existe el nick solicitado\n");
                }
                copyToFileComment(eCommentList, COMMENTS);
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
                        getIdComment(&idComment, "Ingrese el id del comentario\n", "El id no puede ser negativo", 0);
                        if(newLike(eCommentList, idComment)==0)
                        {
                            printf("Like exitoso\n");
                        }else
                        {
                            printf("No se creo el like\n");
                        }
                    }else
                    {
                        printf("Contraseña incorrecta\n");
                    }
                }

                copyToFileComment(eCommentList, COMMENTS);
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
    free(eCommentList);

    return 0;
}
