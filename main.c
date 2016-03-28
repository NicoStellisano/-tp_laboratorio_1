#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <windows.h>

int main()
{
    char seguir = 's';
    int opcion = 0, band = 0, band1 = 0;
    float num1 = 0 , num2 = 0 , resp;

    while(seguir == 's')
    {
        printf("\n1- Ingresar 1er operando (A= %.2f)\n", num1);
        printf("2- Ingresar 2do operando (B= %.2f)\n", num2);
        printf("3- Calcular la suma (%.2f + %.2f)\n", num1,num2);
        printf("4- Calcular la resta (%.2f - %.2f)\n", num1,num2);
        printf("5- Calcular la division (%.2f / %.2f)\n", num1,num2);
        printf("6- Calcular la multiplicacion (%.2f * %.2f)\n", num1,num2);
        printf("7- Calcular el factorial (%.2f!)\n", num1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\nIngrese numero 1: ");
                scanf("%f", &num1);
                printf("\nNumero Ingresado: %.2f \n", num1);
                band=1;//Valida que fue ingresado el primer número
                break;
            case 2:
                system("cls");
                printf("\nIngrese numero 2: ");
                scanf("%f", &num2);
                printf("\nNumero Ingresado: %.2f \n", num2);
                band1=1;//Valida que fue ingresado el segundo número
                break;
            case 3:
                if(band == 1 && band1 ==1)
                {
                    system("cls");
                     resp = suma_de_2(num1,num2);//Suma el numero 1 con el numero 2
                printf("\nLa suma de los numeros es: %.2f", resp);
                }else
                {
                    printf("\nDebe ingresar los 2 numeros\n");
                }
                break;

            case 4:
                if(band == 1 && band1 ==1)
                {
                    system("cls");
                resp = resta_de_2(num1,num2);//Resta el numero 1 con el numero 2
                printf("\nLa resta de los numeros es: %.2f", resp);
                }
                else
                {
                    printf("\nDebe ingresar los 2 numeros\n");
                }
                break;
            case 5:
                if(band == 1 && band1 ==1)
                {
                    system("cls");

                    while(num2==0)
                  {
                     printf("El segundo numero ingresado, debe ser distinto de 0");
                     printf("\nIngrese numero 2: ");
                     scanf("%f", &num2);
                     printf("\nNumero Ingresado: %.2f \n", num2);
                  }

                  resp = division_de_2(num1,num2);//Divide el numero 1 con el numero 2
                  printf("\nLa division de los numeros es: %.2f", resp);
                }
                else
                {
                    printf("Debe ingresar los 2 numeros");
                }
                break;
            case 6:
                if(band == 1 && band1 ==1)
                {
                    system("cls");
                    resp = multiplicacion_de_2(num1,num2);//Multiplica el numero 1 con el numero 2
                    printf("\nLa multiplicacion de los numeros es: %.2f", resp);
                }
                else
                {
                    printf("Debe ingresar los 2 numeros");
                }
                break;
            case 7:
                if(band == 1)
                {
                    system("cls");
                    num1=(double)num1;
                    resp = factorial(num1);//Realiza el factorial del numero 1
                    printf("\nEl Factorial del numero es: %.2Lf", resp);
                }
                else
                {
                    printf("Debe ingresar el 1er numero");
                }
                break;
            case 8:
                if(band == 1 && band1 ==1)
                {
                    num1=(double)num1;
                    system("cls");
                    resp = suma_de_2(num1,num2);
                    printf("\nLa suma de los numeros es: %.2f", resp);
                    resp = resta_de_2(num1,num2);
                    printf("\nLa resta de los numeros es: %.2f", resp);
                    resp = division_de_2(num1,num2);
                    printf("\nLa division de los numeros es: %.2f", resp);
                    resp = multiplicacion_de_2(num1,num2);
                    printf("\nLa multiplicacion de los numeros es: %.2f", resp);
                    resp = factorial(num1);
                    printf("\nEl factorial del numero es: %.2Lf", resp);
                }
                else
                {
                    printf("Debe ingresar los 2 numeros");
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
