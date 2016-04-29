#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int i,j;
    int menor18 = 0,entre18y35 = 0,mayor35 = 0,mayorRango = 0,flag1 = 0,flag2 = 0;//Variables para realizar el gráfico
    long int auxDni,resultado;
    EPersona per[20],auxPer;

    for(i=0;i<20;i++)
    {
        per[i].estado = 0; // Declaro que se pueden utilizar todos los espacios
    }

    while(seguir=='s')
    {
        printf("\n---------------------------------------");
        printf("\n1- Agregar persona                     |\n");
        printf("2- Borrar persona                      |\n");
        printf("3- Imprimir lista ordenada por  nombre |\n");
        printf("4- Imprimir grafico de edades          |\n");
        printf("5- Salir                               |\n");
        printf("---------------------------------------\n\n");

        opcion = getch();//Uso getch para que no se vea el número de opcion ingresado

        switch(opcion)
        {
            case '1':
                resultado = obtenerEspacioLibre(per);

                if(resultado == 22)
                {
                    printf("No hay más espacio en la lista\n");

                }else
                {
                    system("cls");
                    printf("Ingrese Nombre: \n");
                    fflush(stdin);
                    gets(per[resultado].nombre);
                    val_Tam(per[resultado].nombre , 51);
                    printf("Ingrese DNI(Numeros unicamente): \n");
                    scanf("%ld",&per[resultado].dni);
                    printf("Ingrese Edad: \n");
                    scanf("%d",&per[resultado].edad);
                    system("cls");

                    if(per[resultado].edad < 35)
                    {
                        if(per[resultado].edad >= 18)
                        {
                            entre18y35++;
                        }else{
                            menor18++;
                            }
                    }else
                    {
                        mayor35++;
                    }

                    per[resultado].estado = 1; /* Se declara ocupada la posición actual */
                }

                break;


                break;
            case '2':
                printf("Ingrese DNI de la persona a eliminar (Numeros unicamente)\n");
                scanf("%ld",&auxDni);
                resultado = buscarPorDni(per,auxDni);

                if(resultado == 21)
                {
                    system("cls");
                    printf("No se encuentra el DNI ingresado\n");

                }else
                {
                    printf("La persona: %s , con edad: %d. y con el DNI: %ld. Ha sido eliminada\n",per[resultado].nombre,per[resultado].edad,per[resultado].dni);

                    for(i = 49 ; i >= 0 ; i--) // Vacía la variable nombre con espacios
                    {
                        per[resultado].nombre[i] = ' ';
                    }

                    per[resultado].edad = 0;
                    per[resultado].dni = 0;
                    per[resultado].estado = 0;

                }
                break;
            case '3':
                for(i = 0 ; i < 19 ; i++)//Ordenamiento de nombres alfabéticamente
                {
                    for(j = i + 1 ; j < 20 ; j++)
                    {
                        if(strcmp(per[i].nombre , per[j].nombre) > 0)
                        {
                            auxPer = per[i];
                            per[i] = per[j];
                            per[j] = auxPer;


                        }
                    }
                }

                system("cls");

                for(i = 0 ; i < 20 ; i++)//Lista ordenada
                {

                    if(per[i].estado==1)
                    printf("\nNombre:%s\tEdad:%d\tDNI:%ld\n",per[i].nombre,per[i].edad,per[i].dni);
                }


                break;
            case '4':
                if(mayorRango < menor18)
                    mayorRango = menor18;

                if(mayorRango < entre18y35)
                    mayorRango = entre18y35;

                if(mayorRango < mayor35)
                    mayorRango = mayor35;

                system("cls");
                printf("\n\n");

                    for(i=mayorRango; i > 0 ; i--)//Gráfico
                    {
                        if(menor18 >= i)
                        {
                            flag1 = 1;
                            printf("\t*");
                        }

                        if(entre18y35 >= i)
                        {
                            if(flag1 == 0)
                            {
                                printf("\t\t*");
                                flag2 = 1;
                            }

                            if(flag1 ==1)
                            {
                                flag2=1;
                                printf("\t*");
                            }

                        }

                        if(mayor35 >= i)
                        {
                            if(flag2 == 1)
                                printf("\t*");

                            if(flag1 == 1 && flag2 ==0)
                                printf("\t\t*");

                        }
                        printf("\n");
                    }

                    printf("\t<18\t18-35\t>35\n");
                break;
            case '5':
                seguir = 'n';
                break;
        }
        }


    return 0;
}
