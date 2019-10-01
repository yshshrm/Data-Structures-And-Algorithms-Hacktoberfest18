#include<stdio.h>
#include<stdlib.h>

int stack[10], top = -1, size ;


void push()
{
	int item;

	if (top == size-1)
	{
		printf("\n STACK OVERFLOW !!! \n");
	}
	else
	{
		printf("\n Enter the item to be pushed : ");
		scanf("%d",&item);
		top++;
		stack[top] = item;
	}
}


void pop()
{
	if (top == -1)
	{
		printf("\n STACK UNDERFLOW !!!");
	}
	else
	{
		printf("\n Element %d has been popped from the stack \n", stack[top]);
		top--;
	}
}


void display()
{
	int i;

	if (top == -1)
	{
		printf("\n STACK IS EMPTY !!!");
	}
	else
	{
		for (i = top; i >= 0; --i)
		{
			printf("\n -> %d ", stack[i]);
		}
	}
	printf("\n");
}


void main()
{
 	int ch, item;
	
	printf("\n Enter the size of the array : ");
	scanf("%d", &size);
	
	while(1)
	{
		printf("\n 1.PUSH to Stack \n 2.POP from Stack \n 3.DISPLAY \n 4.EXIT");
		printf("\n Enter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: push();
					display();
					break;
			case 2: pop();
					display();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("\n INVALID CHOICE !!!");
		}
	}
}
