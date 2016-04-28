#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(EPersona per[])
{
    int i;

    for(i=0;i<20;i++)
    {
        if(per[i].estado==0)
        {
            return i;
        }
    }

    return 22;// Si se termino el for y no encontró espacio libre, devuelve que no hay mas espacio
}

int buscarPorDni(EPersona per[], long int dni)
{
    int i;

    for(i = 0; i < 20 ; i++)
    {
        if(per[i].dni == dni)
        {
            return i;
        }

    }

    return 21; // Si se termino el for y no encontró el dni en alguna posición, se devuelve error
}
