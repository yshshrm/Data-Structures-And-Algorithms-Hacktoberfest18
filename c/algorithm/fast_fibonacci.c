#include<stdio.h>
#include "../ds/matrix.h"

int fibonacci(int n);
int main()
{
    //Driver program


    int n;

    scanf("%d",&n);

    printf("%d",fibonacci(n));
}

int fibonacci(int n)
{
    Matrix z;
    z.n=2,z.m=2;

    z.mat[0][0]=0;
    z.mat[0][1]=1;
    z.mat[1][0]=1;
    z.mat[1][1]=1;


    lgexp(&z,n);

    Matrix a;
    a.n=2,a.m=1;

    a.mat[0][0]=0;
    a.mat[1][0]=1;

    multiply(&z,&a);

    return z.mat[0][0];

}
