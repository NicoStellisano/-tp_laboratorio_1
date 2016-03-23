#include<conio.h>
#include<stdio.h>
#include<ctype.h>
//prototipo
float factorial (float x);
float factorial (float x)
{
    float resp;
    if(x==1)
        return 1;
    resp=x*factorial(x-1);
    return resp;
}
