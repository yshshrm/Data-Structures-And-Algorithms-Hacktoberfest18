#include<stdio.h>

void insertion_sort(int a[],int n)
{
int i,j,temp;
for(i=1;i<n;i++)
{
	temp = a[i];
	j = i-1;
	while(j>=0 && a[j]>temp)
	{
	a[j+1]=a[j];
	j--;
	}
	a[j+1]=temp;	
}
}
int main()
{
int a[100],n,i;
printf("Enter array size\n");
scanf("%d",&n);
printf("Enter array elements");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
insertion_sort(a,n);
printf("array elements after sort\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
