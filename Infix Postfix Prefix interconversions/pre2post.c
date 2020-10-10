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



st s;
void prepo(char str[])
{
	int n=strlen(str),i=0,j=0,flag=-1,l;


char os[n][n],t[1],k='&';
push('S',&s);
for(i=n-1;i>=0;i--)
{
	if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))                  //operand
	{
		
		push(str[i],&s);
	//	printf("\n%c",peek(s));
	}
	else 													//arranging and storing values of t1,t2 and str[i] 
	{														//in {t1,t2,str[i]} order
		char t1,t2;
		if(peek(s)=='&')									//checking if t1 will be string or not
		{
			pop(&s);
			if(peek(s)=='&')								//checking if t2 will be string or not
			{
				strcat(os[flag],os[flag-1]);
				
				t[0]=str[i];
				t[1]='\0';
				strcat(os[flag],t);
				
				
			}
			else
			{
			t2=peek(s);
			pop(&s);
			j=strlen(os[flag]);
			os[flag][j]=t2;
			os[flag][j+1]=str[i];
			os[flag][j+2]='\0';

			
				push(k,&s);										//"&" is pushed so that we know this is a string
			}
			
			
		}
		else
		{
			t1=peek(s);
			pop(&s);
			if(peek(s)=='&')									//checking if t2 will be string or not
			{
			j=strlen(os[flag]);
			
			for(l=j;l>0;l--)
			{
				os[flag][l]=os[flag][l-1];
			}
				
			
		    os[flag][0]=t1;
			os[flag][j+1]=str[i];
			os[flag][j+2]='\0';
			
			
			}
			else
			{
				t2=peek(s);
				pop(&s);
				flag++;
				
				os[flag][0]=t1;
				os[flag][1]=t2;
				os[flag][2]=str[i];
				os[flag][3]='\0';
				
				push(k,&s);
				
			}
		}
		
	}	
			

}		
	puts(os[flag]);										//Postfix Output
}

int main()
{

	char str[30]="*-A/BC-/AKL";
	printf("Input Prefix string : ");
	puts(str);
	printf("Output Postfix string : ");	
	prepo(str);	
	printf("\n\n");
	return 0;
}