#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[100];
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param puntero a archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie,FILE *f);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param puntero a archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */

int borrarPelicula(EMovie *movie,FILE *f);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param puntero a archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
 int modificarPelicula(EMovie *movie,FILE *f);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param puntero a archivo
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie *movie,FILE *f,FILE *html, char nombre[]);

/**  Genera un menú con las distintas opciones.*/
int Menu();

/**
 *  Valida un numero flotante entre dos valores
 *  @param valor a validar
 *  @param valor minimo
 *  @param valor maximo
 */

float validar_float(float data, float min, float max);

/**
 *  Valida cadena
 *  @param cadena a validar
 *  @param mensaje para recibir cadena del usuario
 *  @param mensaje de error
 *  @param minima cantidad de caracteres
 *  @param maxima cantidad de caracteres
 */
int getString(char* cadena,char mensaje[],char mensError[], int minimo, int maximo);

/**
 *  Valida S o N
 *  @param Caracter a validar
 */
char validar_rta(char rta);

/**
 *  Valida un numero entero entre dos valores
 *  @param valor a validar
 *  @param valor minimo
 *  @param valor maximo
 */
int validar_ent(int data, int min, int max);

#endif // FUNCIONES_H_INCLUDED
