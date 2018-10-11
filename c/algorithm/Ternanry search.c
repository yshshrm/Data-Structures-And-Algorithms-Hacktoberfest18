#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int i, n, val, low, high, mid1, mid2, a[50];
    printf("Enter the size of an array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(values, 5, sizeof(int), cmpfunc);
    printf("The sorted array is : ");
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter the element which you want to search : ");
    scanf("%d", &val);
    low=0;
    high=n-1;

    while(low<=high)
    {
        mid1=((low+high)/2);
        mid2=(mid1*2);

        if(val==a[mid1])
        {
            printf("Position is : %d.\n", mid1+1);
            break;
        }
        else if(a[mid1]>val)
        {
            high=mid1-1;
        }
        else if(val==a[mid2])
        {
            printf("Position is : %d.\n", mid2+1);
            break;
        }
        else if(a[mid2]<val)
        {
             low=mid2+1;
        }
        else
        {
            low=mid1+1;
            high=mid2-1;
        }
    }
    return 0;
}