#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "ArrayList.h"
#define MAXUS 1000

typedef struct {

    char nickName[51];
    char name[51];
    char mail[61];
    char password[21];
    int estado;

}EUsuario;

typedef struct {

    int idComment;
    char nickName[51];
    char comment[200];
    int like;
    int estado;

}EComment;

/**
* @brief inicializa el array con un valor por defecto en el estado
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @return 0 cuando la actualizacion se realice de forma correcta y -1 para errores.
*/
int  initialiceArrayUsuario(EUsuario lista[], int length);

/**
* @brief inicializa el array con un valor por defecto en el estado
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @return 0 cuando la actualizacion se realice de forma correcta y -1 para errores.
*/
int  initialiceArrayComment(EComment lista[], int length);

/**
 * Obtiene el indice que coincide con el nickName pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param nickName correspondiente al usuario.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro nickName(NUll)en caso de no encotrar
 */
EUsuario* findByNick(ArrayList* pList, char nickName[]);

/**
* @brief Alta de usuarios
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @param name nombre del usuario a dar de alta.
* @param mail correo electronico con el que se va a registrar el usuario.
* @param password contraseña del usuario que se va registrar.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int newUser(ArrayList* pList, EUsuario* eUser);

/**
* @brief borra de forma lógica personas
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @param nickName se utilizara para identificar el usuario a modificar.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int modifUser(EUsuario lista[], int length, char nickName[], char name[], char mail[], char password[]);

/**
* @brief borra de forma lógica personas
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @param nickName se utilizara para identificar el usuario a dar de baja.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int deleteUser(EUsuario lista[], int length, char nickName[]);

/**
* @brief Alta de comentarios
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @param nickName alias del usuario.
* @param comment comentario ingresado.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int newComment(EComment lista[], int length, char nickName[], char commet[]);

/**
* @brief Alta de me gusta
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @param nickName alias del usuario.
* @param idComment identificador del comentario.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int newLike(EComment lista[], int length, char nickName[], int idComment);

/**
* @brief Obtiene un nickName valido.
* @param input se inserta el nick validado.
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error.
* @param lowLimit Limite inferior a validar.
* @param hiLimit Limite superior a validar.
* @param lista donde el valor debe ser unico.
* @return Si obtuvo el numero [0] si no [-1]
*/
int getNick(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/**
* @brief Obtiene un nombre valido.
* @param input se inserta el nick validado.
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error.
* @param lowLimit Limite inferior a validar.
* @param hiLimit Limite superior a validar.
* @return Si obtuvo el numero [0] si no [-1]
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* @brief Obtiene un mail valido.
* @param input se inserta el mail validado.
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error.
* @param lowLimit Limite inferior a validar.
* @param hiLimit Limite superior a validar.
* @return Si obtuvo el numero [0] si no [-1]
*/
int getMail(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* @brief Obtiene un idComment valido.
* @param input se inserta el id validado.
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error.
* @param lowLimit Limite inferior a validar.
* @param hiLimit Limite superior a validar.
* @return Si obtuvo el numero [0] si no [-1]
*/
int getIdComment(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* @brief Informe del usuario con mayor cantidad de comentarios.
* @param input se inserta el id validado.
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error.
* @param lowLimit Limite inferior a validar.
* @param hiLimit Limite superior a validar.
* @return Si obtuvo el numero [0] si no [-1]
*/
void informes(EUsuario listaUsu[], int lengthUsu, EComment listaComment[], int lengthComm);

#endif // FUNCIONES_H_INCLUDED
