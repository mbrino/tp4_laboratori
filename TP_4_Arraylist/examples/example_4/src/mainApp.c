/*******************************************************************
*Programa:Trabajo Practico 4
*
*Objetivo:
    Desarrollar librerias genericas para el manejo de punteros.
    Desarrollar una aplicación que utilice estas librerias
*
*Version:0.1 del 15 Junio 2016
*Autor:Matias Brino
*
********************************************************************/


#include "../inc/ArrayList.h"


int main()
{
    while(seguir=='s')
    {
        system("cls");
        printf("*****************************************\n*                                       *\n");
        printf("* 1- Agregar usuario                    *\n");
        printf("* 2- Modificar usuario                  *\n");
        printf("* 3- Eliminar usuario                   *\n");
        printf("* 4- Nuevo comentario                   *\n");
        printf("* 5- Me gusta                           *\n");
        printf("* 6- Salir                              *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            default:
                printf("La opcion ingresada no es valida, vuelva a ingresar un valor\n");
                system("pause");
                break;
}
