#include <stdio.h>
#define max 10
int stack[max];
int top=-1;

void push(int val) {
    if (top==max-1)
    {
        printf("Stack overflow:\n");
        return;
    }
    top++;
    stack[top] = val;
}

int pop() {
    int tmp;
    if (top==-1)
    {
        printf("Stack underflow:\n");
        return 0;
    }
    tmp = stack[top];
    top--;
    return tmp;
}
void binary(int num) {
    int i=0;
    while (num!=0)
    {
        push(num % 2);
        num = num / 2;
    }
    while (top!=-1)
    {
       printf(" %d ",pop()); 
    
    }
    
}
void main()
{
    int num;
    printf("Enter any number for binary:\n");
    scanf("%d", &num);
    binary(num);
}
