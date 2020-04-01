#include<stdio.h>
//Find the largest value of array
main()
{
	int a[5],b,i;
	
	printf("Enter the value of array:\n");
	for(i=0;i<5;i++)
	{	scanf("%d",&a[i]);}
	b=a[0];
	for(i=0;i<=5;i++)
	{ 
	if(b<a[i])
	b=a[i];	
	}
 printf("The largest number is: %d\n",b);}
