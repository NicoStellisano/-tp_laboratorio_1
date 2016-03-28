#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include "D:\Mis Documentos\libreriacrear.c"
main()
{
    double num,resp;
    printf("Ingrese numero\n");
    scanf("%Lf",&num);
    resp=factorial(num);
    printf("El factorial del numero: %Lf, es: %Lf",num,resp);
}

