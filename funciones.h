#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<conio.h>
#include<stdio.h>
#include<ctype.h>
//prototipo
float factorial (double x); // Factorial
float suma_de_2 (float a,float b); // Suma
float resta_de_2 (float a,float b); // Resta
float multiplicacion_de_2 (float a,float b); //Multiplicación
float division_de_2 (float a,float b); // División

//Desarrollo
float factorial (double x)
{
    double resp;
    if(x==1)
        return 1;
    resp=x*factorial(x-1);
    return resp;
}

float suma_de_2 (float a,float b)
{
  float suma;
  suma=a+b;
  return suma;
}

float resta_de_2 (float a,float b)
{
  float resta;
  resta=a-b;
  return resta;
}

float multiplicacion_de_2 (float a,float b)
{
  float multiplicacion;
  multiplicacion=a*b;
  return multiplicacion;
}

float division_de_2 (float a,float b)
{
  float division;
  division=a/b;
  return division;
}
#endif
