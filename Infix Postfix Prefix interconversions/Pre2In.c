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
void prein(char str[])
{
	int n=strlen(str),i=0,j=0,flag=-1,l;


char os[n][n+n+2],t[1],k='&';
push('S',&s);
for(i=n-1;i>=0;i--)
{
	if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))                  //operand
	{
		
		push(str[i],&s);
	
	}
	else													//arranging and storing values of t1,t2 and str[i] 
	{														//in {'(',t1,str[i],t2,')'} order
		char t1,t2;
		if(peek(s)=='&')									//checking if t1 will be string or not
		{
			pop(&s);
			if(peek(s)=='&')								//checking if t2 will be string or not
			{
				
				j=strlen(os[flag]);
				for(l=j;l>0;l--)
					os[flag][l]=os[flag][l-1];
				os[flag][0]='(';
				os[flag][j+1]='\0';
				j=strlen(os[flag-1]);
				for(l=j;l>0;l--)
					os[flag-1][l]=os[flag-1][l-1];
				
				os[flag-1][0]=str[i];
				os[flag-1][j+1]=')';
				os[flag-1][j+2]='\0';
				strcat(os[flag],os[flag-1]);
				
				
			}
			else
			{
			t2=peek(s);
			pop(&s);
			j=strlen(os[flag]);
			for(l=j;l>0;l--)
			{
				os[flag][l]=os[flag][l-1];
			}
			os[flag][0]='(';
			os[flag][j+2]=t2;
			os[flag][j+1]=str[i];
			os[flag][j+3]=')';
			os[flag][j+4]='\0';

			
				push(k,&s);									//"&" is pushed so that we know this is a string
			}
			
			
		}
		else
		{
			t1=peek(s);
			pop(&s);
			if(peek(s)=='&')								//checking if t2 will be string or not
			{
			j=strlen(os[flag]);
			
			for(l=j+2;l>2;l--)
			{
				os[flag][l]=os[flag][l-3];
			}
				
			os[flag][0]='(';
		    os[flag][1]=t1;
			os[flag][2]=str[i];
			os[flag][j+3]=')';
			os[flag][j+4]='\0';
			
			
			}
			else
			{
				t2=peek(s);
				pop(&s);
				flag++;
				os[flag][0]='(';
				os[flag][1]=t1;
				os[flag][2]=str[i];
				os[flag][3]=t2;
				os[flag][4]=')';
				os[flag][5]='\0';
				
				push(k,&s);
				
			}
		}
		
	}	
		
	

}		
	puts(os[flag]);											//Infix Output
}

int main()
{

	char str[30]="+a+*bcd";
	printf("Input Prefix String : ");	
	puts(str);
	printf("Output Infix String : ");	
	prein(str);	
	printf("\n\n");
	return 0;
}