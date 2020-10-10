#include<stdio.h>

#include<string.h>

#define maxsize 100

typedef struct stack
{
	char st[maxsize];	
	int top;
}st;



//Push Function

void push(char n,st *s)													
{
		s->top=s->top+1;
		s->st[s->top]=n;	
}


//Pop function


void pop(st *s)
{
	
	if(s->top==-1)
		return;
	else
	{	
		s->top=s->top-1;
		
	}
}


//Peek Function


char peek(st s)
{
	return 	s.st[s.top];					
}


int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
	{
		return -1;
	}
}
st s;
void inpo(char str[])
{
	int n=strlen(str),i=0,j=0;


char os[n];
push('S',&s);
while(i<n)
{
	if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))                  //operand
	{
		os[j]=str[i];
		j++;
	}
	else if(str[i]=='(')
		 {
		 	push(str[i],&s);
		 }
		 else if(str[i]==')')
		 {
		 	while(peek(s)!='S'&&peek(s)!='(')      //a+b*(c^d-e)^(f+g*h)-i
			 {
			 	char c=peek(s);
			 	pop(&s);
			 	os[j]=c;
			 	j++;
			 }
			 if(peek(s)=='(')
			 {
 	   			char c=peek(s);
					pop(&s);	
			 }
		 }
		 else
		 {
		 	 while(peek(s)!='S'&&prec(str[i])<=prec(peek(s)))
			  {
			  	char c=peek(s);
			  	pop(&s);
			  	os[j]=c;
			  	j++;
			  }
		 push(str[i],&s);
		 }
	
	i++;
}	
while(peek(s)!='S')
{
	char c=peek(s);
	pop(&s);
	os[j]=c;
	j++;
}
os[j]='\0';
for(i=0;os[i]!='\0';i++)					//Postfix output
	printf("%c",os[i]);
}


int main()
{
		char str[30]="((A+B-C)*D^E^F)/G^H+Q";
printf("Infix string : ");
puts(str);
printf("\nOutput Postfix String : ");
	inpo(str);	
	printf("\n\n");
	return 0;
}