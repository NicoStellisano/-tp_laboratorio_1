#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
  int cont=0;
int agregarPelicula(EMovie *movie,FILE *f)
{
    int i;
    int auxInt,auxInt2;
    char auxCad[500];


    getString(auxCad,"Ingrese Titulo de Pelicula:\n","Titulo Excede los 20 caracteres\n",0,20);
    strcpy(movie->titulo,auxCad);

    getString(auxCad,"Ingrese Genero de Pelicula:\n","Genero Excede los 20 caracteres\n",0,20);
    strcpy(movie->genero,auxCad);

    printf("Ingrese Duracion de Pelicula: \n");
    scanf("%d",&auxInt);
    movie->duracion = validar_ent(auxInt,0,999);

    getString(auxCad,"Ingrese Descripcion de Pelicula\n","Descripcion Excede los 500 caracteres\n",0,500);
    strcpy(movie->descripcion,auxCad);

    printf("Ingrese Puntaje de Pelicula (0-100):\n");
    scanf("%d",&auxInt2);
    movie->puntaje = validar_ent(auxInt2,0,100);

    getString(auxCad,"Ingrese Link de Imagen, de la Pelicula\n","Link Excede los 100 caracteres\n",0,100);
    strcpy(movie->linkImagen,auxCad);
    cont++;

    movie->estado = 1;

    fseek(f,0L,SEEK_END);
    fwrite(movie,sizeof(EMovie),1,f);



    return 0;



}

int borrarPelicula(EMovie *movie,FILE *f)
{
    char movieBuscada[100];

    getString(movieBuscada,"Ingrese Titulo de Pelicula a borrar:\n","Titulo Excede los 20 caracteres\n",0,20);


    rewind(f);
   while((fread(movie,sizeof(EMovie),1,f))!=0)//Mientras no llege al final del archivo
    {

        if(strcmp(movieBuscada,movie->titulo)==0)
        {
            fseek(f,(-1)*sizeof(EMovie),SEEK_CUR);//Ir una posicion atras del registro para borrarlo
            movie->estado = 0;
            fwrite(movie,sizeof(EMovie),1,f);
            printf("Se ha borrado la Pelicula");
            system("pause");
            cont--;
            break;

        }

    }
return 0;
}

int modificarPelicula(EMovie *movie,FILE *f)
{
    char movieBuscada[100];
     int auxInt;
    char auxCad[500];

    getString(movieBuscada,"Ingrese Titulo de Pelicula a modificar:\n","Titulo Excede los 20 caracteres\n",0,20);
    rewind(f);
    while((fread(movie,sizeof(EMovie),1,f))!=0)//Mientras no llege al final del archivo
    {

        if(strcmp(movieBuscada,movie->titulo)==0)
        {
            fseek(f,(-1)*sizeof(EMovie),SEEK_CUR);//Ir una posicion atras del registro para modificarlo
            getString(movieBuscada,"Ingrese Genero de Pelicula:\n","Genero Excede los 20 caracteres\n",0,20);
            strcpy(movie->genero,movieBuscada);

            printf("Ingrese Duracion de Pelicula: \n");
            scanf("%d",&auxInt);
            movie->duracion = validar_ent(auxInt,0,999);

            getString(auxCad,"Ingrese Descripcion de Pelicula\n","Descripcion Excede los 500 caracteres\n",0,500);
            strcpy(movie->descripcion,auxCad);

            printf("Ingrese Puntaje de Pelicula (0-100):\n");
            scanf("%d",&auxInt);
            movie->puntaje = validar_ent(auxInt,0,100);

            getString(auxCad,"Ingrese Link de Imagen, de la Pelicula\n","Link Excede los 100 caracteres\n",0,100);
            strcpy(movie->linkImagen,auxCad);

             fwrite(movie,sizeof(EMovie),1,f);
            break;

        }

    }
    return 0;
}

void generarPagina(EMovie *movie,FILE *f,FILE *html, char nombre[])
{

    html = fopen(nombre,"w");
    int i=0;


fprintf(html,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
rewind(f);
   while((fread(movie,sizeof(EMovie),1,f))!=0)
            {


            if(movie->estado!=1)
            {
                movie->estado=0;

            }

               if(movie->estado==1)
               {
                    fprintf(html,
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n",movie->linkImagen,movie->titulo,movie->genero,movie->puntaje,movie->duracion,movie->descripcion);
               }

            }

            fprintf(html,
            "</div>\n"
            "</div>\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");

    fclose(html);
    fclose(f);
    exit(1);
        }

int validar_ent(int data, int min, int max)
{
    while(data < min || data > max)
    {
        printf("\nError, debe ingresar un valor entre %d y %d\n", min , max);
        scanf("%d", &data);
    }
    return data;
}

char validar_rta(char rta)
{
        do
        {
        printf("\nDesea continuar, s/n:\n");
        rta = tolower(getch());
        }while(rta != 's' && rta != 'n');

        return rta;
}

int getString(char* cadena,char mensaje[],char mensError[], int minimo, int maximo){
    char aux[500];
    do{
        printf("%s", mensaje);
        fflush(stdin);
        gets(aux);
        if(strlen(aux) < minimo || strlen(aux)>maximo){
            printf("%s", mensError);
        }else{
            strcpy(cadena,aux);
            return 0;
        }
    }while(strlen(aux) < minimo || strlen(aux)>maximo);
}

float validar_float(float data, float min, float max)
{
    while(data < min || data > max)
    {
        printf("\nError, debe ingresar un valor entre %f y %f\n", min , max);
        scanf("%f", &data);
    }
    return data;
}

int Menu()
{
    int op;
    printf("\n---------------------------------------");
    printf("\n1- Agregar Pelicula                    |\n");
    printf("2- Borrar Pelicula                     |\n");
    printf("3- Modificar Pelicula                  |\n");
    printf("4- Generar Pagina Web                  |\n");
    printf("5- Salir                               |\n");
    printf("---------------------------------------\n\n");
    op = getch();

    return op;
}

 //while((fread(movie,sizeof(EMovie),1,pointDat))!=0)
