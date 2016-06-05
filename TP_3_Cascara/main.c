#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    EMovie movie;
    FILE *f;
    FILE *html;

    f = fopen("datos.dat","rb+");

    if(f == NULL)
    {
        f = fopen("datos.dat","wb+");

        if(f == NULL)
        {
            printf("No se pudo crear");
            exit(1);
        }
    }

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {

        switch(Menu())
        {
            case '1':
                agregarPelicula(&movie,f);
                break;
            case '2':
                borrarPelicula(&movie,f);
                break;
            case '3':
                modificarPelicula(&movie,f);
               break;
            case '4':
                generarPagina(&movie,f, html, "index.html");
                break;
            case '5':
                seguir = 'n';
                break;
        }
    }

    return 0;
}
