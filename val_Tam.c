#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
void val_Tam(char x[], int tam)
{
    while(strlen(x)>tam-1)
    {
        printf("Error. Reingrese una cadena que no exceda los %d caracteres:\n",tam-1);
        fflush(stdin);
        gets(x);

    }
}
