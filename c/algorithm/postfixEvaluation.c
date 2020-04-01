#include<stdio.h>
#include<ctype.h>
#include<string.h>


int top=-1, stack[15];


void push(char x)
{
    stack[++top] = x;
}


char pop()
{ 
	return stack[top--];
}


void postfixEvaluation(char postfix[])
{
    char ch;
    int a,b,i;

    for(i=0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch-'0');
        }

        else
        {
            b = pop();
            a = pop();
                
            switch(ch)
            {
              case '+': push(a+b);
                break;
              case '-': push(a-b);
                break;
              case '*': push(a*b);
                break;
              case '/': push(a/b);
                break;
            }
        }   
    }

    printf("\n The postfix evaluation is   : %d", stack[top]);
}


void main()
{
    char infix[15],postfix[15];

    printf("\n Enter the postfix expression  : ");
    scanf("%s", postfix);

    postfixEvaluation(postfix);
    printf("\n");
}
