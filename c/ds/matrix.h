#ifndef MATRIX_H
#define MATRIX_H
#define MAXN 100

#include<stdio.h>

typedef struct
{
    int n,m;
    int mat[MAXN][MAXN];
}Matrix;

void multiply(Matrix* a,Matrix* b);//multiplies matrices a and b storing the result into a

void identity(Matrix* a); //sets matrix a as the identity matrix

void zero(Matrix* a); //sets matrix a as the zero matrix

void cpy(Matrix* a,Matrix* b); //copies elements of matrix b into matrix a

void lgexp(Matrix* a,int b); //raises matrix square matrix a to bth power in O(log(b))

void print(Matrix* a,FILE* f); //prints matrix to specified file
#endif // MATRIX_H
