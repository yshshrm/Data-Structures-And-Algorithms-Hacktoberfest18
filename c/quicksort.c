#include <stdio.h>
#include <stdlib.h>
int partition(int*,int,int,int);
void rquicksort(int *arr, int i, int j)
{
    if(i<j)
    {
      int pivot = arr[rand()%(j-i+1)+i];
      //int pivot = arr[j];
      int k = partition(arr,i,j,pivot);
      rquicksort(arr,i,k);
      rquicksort(arr,k+1,j);
    }
}
int partition(int *arr,int i,int j,int pivot)
{
    int l = i;
    int r = j;
    while(l<=r)
    {
      if(l<=r)
      {
      	while(arr[l]<=pivot)
      	{
         	l++;
      	}
      }
      if(l<=r)
      {
      	while(arr[r]>pivot)
      	{ 
          	r--;
        }
      }
      int temp = 0;
      if(l<r)
      {
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        r--;
        l++;
      }
    }
    return r;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    rquicksort(arr,0,n-1);
    for(int i = 0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
