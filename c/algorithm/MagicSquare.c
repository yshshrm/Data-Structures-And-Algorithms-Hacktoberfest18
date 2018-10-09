#include <stdio.h>

void mgs(int size, int a[][10])
{
    int s = size * size;
    int i = 0, j = size / 2, k;

    for (k = 1; k <= s; ++k)
    {
        a[i][j] = k;
        i--;
        j++;

        if (k % size == 0)
        {
            i += 2;
            --j;
        }
        else
        {
            if (j == size)
                j -= size;
            else if (i < 0)
                i += size;
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main( )
{
    int size;
    int a[10][10];
    printf("Enter the size of the square (odd only): ");
    scanf("%d", &size);
    if (size % 2 == 0)
    {
        printf("An even number was entered");
    }
    else
    {
        mgs(size, a);
    }
}
