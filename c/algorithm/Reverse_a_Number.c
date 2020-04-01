#include<stdio.h>

int main()
{
	int sum=0,num,r;
	
	scanf("%d",&num);
	// 1 2 3 4
	while(num>0)
	{
		r=num%10; // r=4
		sum=sum*10 + r ;// for concatenating the numbers
		num=num/10 ;// new num
	}
	printf("%d",sum);
	return 0;
}