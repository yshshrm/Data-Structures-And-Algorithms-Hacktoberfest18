// Algorithm for solving simultaneous equations using Gauss Jordan method

#include<stdio.h>
#include<stdlib.h>
void gauss_jordan(float matrix[20][20], int r, int c)
{
    for(int k=0; k<r; k++)
    {
        int row=k;
        for(int i=0; i<r ; i++)
        {
            if(i>row)
            {
                if (matrix[k][k]==0 && k<c)
                {
                    for (int a=k; a<c; a++)
                        matrix[k][a] += matrix[k+1][a];
                }
                float constant = matrix[i][k]/matrix[k][k];
                for (int j=k; j<c;j++)
                {
                    matrix[i][j] = matrix[i][j] - constant * matrix[k][j];
                }
            }
        }
    }
    printf("\n");
    for (int i=0; i<r;i++)
    {
        printf("x%d = %0.2f\n", i+1, matrix[i][c-1]/matrix[i][i]);
    }
    printf("\n");
    for (int i=0;i<r; i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("%0.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int row , coloumn;
    float matrix[20][20];
    printf("Enter the size of the matrix: ");
    scanf("%d %d", &row, &coloumn);
    for (int i=0;i<row; i++)
    {
        for (int j=0;j<coloumn;j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
    for (int i=0;i<row; i++)
    {
        for (int j=0;j<coloumn;j++)
        {
            printf("%0.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    gauss_jordan(matrix, row, coloumn);
    return 0;
}
