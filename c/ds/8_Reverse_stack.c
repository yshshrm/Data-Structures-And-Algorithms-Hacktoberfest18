// 17CSE1029 - ARCHIT

// To reverse a stack using recursion. You are not allowed to use loop
// constructs like while, for..etc, and you can only use the functions isEmpty(S), push(),
// pop() on Stack S.

#include <stdio.h>
#include <stdlib.h>
#define size 100

int isempty(int top){
	return top == -1;
}

int isfull(int top){
	return top == size-1;
}

void push(int Element, int stack[], int *top){
	if(isfull(*top)){
		printf("\t\tStack Overflow!\n\n");
		return;
	}
	stack[++*top] = Element;
}

int pop(int stack[], int *top){
	if(isempty(*top)){
		printf("\t\tStack Underflow!\n\n");
		return -1;
	}
	int temp = *top;
	*top = *top-1;
	return stack[temp];
}
void display(int stack[] , int top){
	int i;
	for(i=top; i>=0; i--){
		printf("| %d |\n", stack[i]);
		printf("|___|\n");
	}
	printf("\n");
}

void push_at_last(int element, int stack[], int *top) {
	if(*top < 0) {
		push(element, stack, top);
	}
	else {
		int ele = pop(stack, top);
		push_at_last(element, stack, top);
		push(ele, stack, top);
	}
}
void stack_reverse(int stack[], int *top)
{
  if(*top >= 0) {
		int a = pop(stack, top);
		stack_reverse(stack, top);
		push_at_last(a, stack, top);
	}
}

int main() {
  int Element, a;
	int stack[size];
	int top=-1;
	while(1){
		printf("1. Want to Push\n");
		printf("2. Want to Pop\n");
		printf("3. Display the stack\n");
		printf("4. Reverse using recursion\n");
		printf("5. Exit the code\n\n");

		scanf("%d", &a);
		if(a==5){
			break;
		}

		switch(a){

			case 1	: printf("\t Enter element in stack :");
				  			scanf("%d", &Element);
				  			push(Element, stack, &top);
				  			break;
			case 2	: printf("%d is popped\n", pop(stack, &top));
				  			break;
			case 3 	: display(stack, top);
				  			break;
			case 4 	: stack_reverse(stack, &top);
				  			break;
			default	: printf("Invalid Input\n\n");
				  			break;
		}
	}
	return 0;
}
