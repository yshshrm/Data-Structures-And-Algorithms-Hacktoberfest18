#include<bits/stdc++.h>
#define MAX 10
using namespace std;

class Stack
{
	int stack[MAX];
	int top;
	public:
		Stack() {
			top=-1;
		}
		int push(int e);
		
		
		int pop()
		{
			if(top<0)
			{
				cout<<"Stack Underflow\n";
				return 0;
			}
			top--;
			return(stack[top+1]);
		}
		
		int traverse()
		{
			for(int i=top;i>=0;i--)
			cout<<stack[i]<<" ";
			cout<<endl;
		}
};
int Stack::push(int e)
		{
			if(top+1>=MAX)
			{
				cout<<"Stack Overflow\n";
				return 0;
			}
			top++;
			stack[top]=e;
		}
int main()
{
	int n=0,e=0;
	Stack s;
	while(1)
	{
		cout<<"1.Push     2.Pop     3.Traverse      4.Exit\n";
		cin>>n;
		switch(n)
		{
			case 1:
				cin>>e;
				s.push(e);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.traverse();
				break;
			case 4:
				return 0;
			default:
				cout<<"Please choose b/w 1/2/3/4\n";
		}
	}
	
}

