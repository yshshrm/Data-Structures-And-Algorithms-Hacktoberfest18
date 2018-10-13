//SUM OF THE DIGITS OF A NUMBER
#include<stdio.h>
int main()
{
	int i,sum=0,num;
	scanf("%d",&num);
	while(num!=0)
	{
		r=num%10;
		sum=sum+r;
		num=num/10;
	}
	printf("%d",sum);
}