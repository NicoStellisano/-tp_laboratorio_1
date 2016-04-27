#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
* Estructura de una persona.
* @var nombre Obtiene el nombre de la persona.
* @var edad  Obtiene la edad de la persona.
* @var estado  Obtiene la posición de la estructura en la que se guarda la persona.
* @var dni Obtiene el DNI de la persona.
*/
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona per[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona per[], long int dni);

/**
 * Valida si el tamaño de la cadena ingresada supera el de la variable "tam".
 * @param x el array se pasa como parametro.
 * @param tam el tamaño que no debe superarse.
 */
void val_Tam(char x[], int tam);
#endif // FUNCIONES_H_INCLUDED
