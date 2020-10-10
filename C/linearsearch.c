#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(arr[i] == key)
        {
            printf("%d is found at index %d",key,i);
            break;
        }
        if(i == n-1 && arr[i] != key)
        {
            printf("Element not found");
        }
    }
    return 0;
}
