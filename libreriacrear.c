#include<conio.h>
#include<stdio.h>
#include<ctype.h>
//prototipo
float factorial (double x);
float factorial (double x)
{
    double resp;
    if(x==1)
        return 1;
    resp=x*factorial(x-1);
    return resp;
}
