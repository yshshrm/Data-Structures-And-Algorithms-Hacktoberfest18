#include<stdio.h>
#include<conio.h>
void insertionsort(int arr[],int n)
{int i,j;
int key;
for(i=1;i<n;i++)
{key=arr[i];
j=i-1;
while(j>=0&&arr[j]>key)
{arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
printf("\n");
printf("array after insertion sort");
for(i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n");}
int main()
{int arr[5],n;
int i;
printf("enter values");
for(i=0;i<5;i++)
{scanf("%d",&arr[i]);}
insertionsort(arr,5);
return 0;
}
