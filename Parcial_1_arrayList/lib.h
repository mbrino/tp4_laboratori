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
int modifUser(ArrayList* pList, void* pElement, void* pElementCpy);

/**
* @brief borra de forma lógica personas
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @param nickName se utilizara para identificar el usuario a dar de baja.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int deleteUser(ArrayList* pList, void* pElement);

/**
* @brief Alta de comentarios
* @param pList puntero al arrayList.
* @param nickName alias del usuario.
* @param comment comentario ingresado.
* @return NULL si no se pudo agregar el nuevo comentario
*/
EComment* newComment(ArrayList* pList, char nickName[], char commet[]);

/**
* @brief Alta de LIKES
* @param lista el array se pasa como parametro.
* @param nickName alias del usuario.
* @param idComment identificador del comentario.
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int newLike(ArrayList* pList, int idComment);

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
int getIdComment(int* input,char message[],char eMessage[], int lowLimit);

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

/**
* @brief Genera un nuevo id de forma secuencial para un arrayList
* @param pList arrayList a partir del cual se generará el secuencial.
* @return -1 si no se pudo generar el id.
*/
int newIdComment(ArrayList* pList);

/**
* @brief Lee desde un archivo y lo copia a un arrayList
* @param pList arrayList que guardara
* @param pFile puntero del archivo
* @return -1  si falla 0 si la copia es exitosa
*/
int readFromFileUser(ArrayList* pList, char nombre[]);

/**
* @brief guarda la informacion del arrayList en un archivo
* @param pList arrayList que guardara
* @param pFile puntero del archivo
* @return -1  si falla 0 si la copia es exitosa
*/
int copyToFileUser(ArrayList* pList, char nombre[]);

/**
* @brief Lee desde un archivo y lo copia a un arrayList
* @param pList arrayList que guardara
* @param pFile puntero del archivo
* @return -1  si falla 0 si la copia es exitosa
*/
int readFromFileComment(ArrayList* pList, char nombre[]);

/**
* @brief guarda la informacion del arrayList en un archivo
* @param pList arrayList que guardara
* @param pFile puntero del archivo
* @return -1  si falla 0 si la copia es exitosa
*/
int copyToFileComment(ArrayList* pList, char nombre[]);
#endif // FUNCIONES_H_INCLUDED
