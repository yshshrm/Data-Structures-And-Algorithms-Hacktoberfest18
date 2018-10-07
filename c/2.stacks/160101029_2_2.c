#include <stdio.h>
#include <stdlib.h>

struct node
{
	int day;
	int price;
	int span;
};
struct node *stack;
int top=-1;

void pop()
{
	if(top==-1)
		return;
	top--;
	
}

int findSpan(int X)
{
	int count=1;
	while(stack[top].price<=X&&top!=-1)
	{
		count++;
		pop();
	}
	return count;
}



int main()
{
	int n,i;
	scanf("%d",&n);
	stack=(struct node *)malloc(n*sizeof(struct node));
	for(i=0;i<n;i++)
	{
		stack[i].day=i;
		scanf("%d",&stack[i].price);
		stack[i].span=findSpan(stack[i].price);
		top=i;
	}
	printf("Day\tPrice\tSpan\n");
	while(top!=-1)
	{
		printf(" %d\t %d\t %d\n",stack[top].day,stack[top].price,stack[top].span);
		pop();
	}


	return 0;
}