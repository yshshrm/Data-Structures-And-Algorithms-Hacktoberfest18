#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,j;			//declaring variables


	scanf("%d",&n);		//taking input of No. of variables


	int *x=(int *)malloc(n*sizeof(int));		//array memory allocation  to store prices

	//taking input and storing it in array
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);


	int *s=(int *)malloc(n*sizeof(int));		//array memory allocation to store span 


	s[0]=1;		//span of day 0 is always 1


	int count;		//temporary variable to calculate span

	for(i=1;i<n;i++)
	{
		count=1;	//initialzing count

		j=i-1;      //innitializing j

		//run loop till price greater then x[i] is found
		while(x[j]<=x[i]&&j>=0)
		{
			count++;		//incrementing count
			j--;			//decrementing j
		}


		s[i]=count;			//storing count in span array
	}

	//printing result
	printf("Day\tPrice\tSpan\n");
	for(i=0;i<n;i++)
		printf(" %d\t %d\t %d\n",i,x[i],s[i]);

	return 0;
}