/*
Title - Regula Falsi
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-8

int itr=0;

float func (float x)
{
    return (x*x - 10);
}

void regulafalsi(float a, float b)
{
    
    if (func(a)*func(b) >= 0)
    {
        printf("\nIncorrect choice of a and b\n");
        return;
    }

    float c=a;
    do
    {
        c = (b*func(a)-a*func(b))/(func(a)-func(b));
        ++itr;
        if (func(c)== 0.0)
        {
            break;
        }
        else if (func(a)*func(c)<0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }while (fabs(func(c)) >= TOL);
    printf("\nRoot = %f\n", c);
    printf("Number of Iterations = %d", itr);
}

int main()
{
    float a,b;
    a=3.00; b=4.00;
    regulafalsi(a,b);
    return 0;
}
