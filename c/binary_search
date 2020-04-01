#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter no of elements in array\t");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter elements respectively\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int no;
    printf("\nenter no to search in array\t");
    scanf("%d",&no);
    int s = n;

    int first, last, middle;
    first = 0;
    last = s-1;
    middle = (first + last)/2;

    while(first<=last)
    {
        if(no == arr[middle])
        {
            printf("\nno %d exists at position no %d.",no,middle+1);
            break;
        }
        else if(arr[middle] < no)
            first = middle +1;
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if(first > last)
        printf("\nno does not exist :(\n");


}
