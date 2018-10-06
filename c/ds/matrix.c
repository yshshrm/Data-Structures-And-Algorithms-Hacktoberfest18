#include "matrix.h"

void cpy(Matrix* a,Matrix* b)
{
    a->n=b->n;
    a->m=b->m;

    int i,j;
    for(i=0;i<a->n;i++)
    {
        for(j=0;j<b->m;j++)
        {
            a->mat[i][j]=b->mat[i][j];
        }
    }
}
void identity(Matrix* a)
{

    if(a->n != a->m)
    {
        fprintf(stderr,"Matrix is not  a square matrix!");
        return;
    }
    zero(a);
    int i;
    for(i=0;i<a->n;i++)
    {
        a->mat[i][i]=1;
    }
}

void zero(Matrix* a)
{
    int i,j;
    for(i=0;i<a->n;i++)
    {
        for(j=0;j<a->m;j++)
        {
            a->mat[i][j]=0;
        }
    }
}

void multiply(Matrix* a,Matrix* b)
{
    if(a->m != b->n)
    {
        fprintf(stderr,"Can't multiply matrices!");
        return;
    }
    Matrix c;
    c.n=a->n;
    c.m=b->m;
    zero(&c);
    int i,j,k;
    for(i=0;i<a->n;i++)
    {
        for(j=0;j<b->m;j++)
        {
            for(k=0;k<a->m;k++)
            {
                c.mat[i][j]+=a->mat[i][k]*b->mat[k][j];
            }
        }
    }

    cpy(a,&c);
}

void lgexp(Matrix* a,int b)
{
    if(a->n != a->m)
    {
        fprintf(stderr,"Matrix is not  a square matrix!");
        return;
    }
    if(b==0)
    {
        identity(a);
    }
    else
    {
        Matrix r;
        r.n=a->n;
        r.m=a->m;
        identity(&r);

        while(b>1)
        {
            if(b%2==0)
            {
                multiply(a,a);
            }
            else
            {
                multiply(&r,a);
                multiply(a,a);
            }

            b/=2;
        }
        multiply(a,&r);
    }
}

void print(Matrix* a,FILE* f)
{
    for(int i=0;i<a->n;i++)
    {
        for(int j=0;j<a->m;j++)
        {
            fprintf(f,"%d ",a->mat[i][j]);
        }
        fprintf(f,"\n");
    }
}
