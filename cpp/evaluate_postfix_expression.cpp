#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 10

using namespace std;

class stack
{
	int data[SIZE];
	int top;
public:
	void push(int);
	int pop();
	stack()
	{
		top=-1;
	}

};

void stack :: push(int value)
{
	if(top==SIZE-1)
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	data[++top]=value;
}

int stack :: pop()
{
	if(top==-1)
	{
		return -9999;
	}
	int value=data[top--];
	return value;
}

int operate(int left,int right,char expression)
{
	int result;
	switch(expression)
	{
		case '+': result = left + right;
			  break;
		case '-': result = left - right;
			  break;
		case '*': result = left * right;
			  break;
		case '/': result = left / right;
			  break;
		case '^': result = pow(left,right);
			  break;
	}
	return result;
}

int main()
{
	stack s1;
	char exp[100];
	int num,left,right,result;
	cout<<"Enter Postfix Expression to be evaluated"<<endl;
	cin>>exp;
	int l=strlen(exp);
	for(int i=0 ; i<l ; i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
		{
			num = exp[i]-'0';
			s1.push(num);
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
		{
			right=s1.pop();
			left=s1.pop();
			result = operate(left,right,exp[i]);
			s1.push(result);
		}
		else
		{
			cout<<"Wrong Expression Recieved";
			exit(1);
		}
	}

	cout<<"Result of the Postfix Expression is : "<<s1.pop()<<endl;

}

