/*
Title - Newton Raphson Method
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-4

//Function to find the roots of
double func (double x)
{
    return (x*x - 10);
}

//Derivative of said function
double derfunc (double x)
{
    return (2*x);
}

double newt(double a)
{
	double b;
	int i=0;
	do{
		i++;
	    b = a - func(a)/derfunc(a);
	    if(func(b)==0)
	    {
	        printf("Root = %lf",b);
	        return 0;
	    }
	    printf("\nAfter %d iterations, Value = %lf",i,b);
	    a=b;	    
	}while(func(b)>TOL);
}

int main()
{
    printf("Enter initial guess \n");
    double a;
    scanf("%lf",&a);
    newt(a);
}
