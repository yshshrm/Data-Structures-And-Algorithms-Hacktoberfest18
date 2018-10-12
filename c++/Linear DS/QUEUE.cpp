#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

class Queue
{
	int queue[MAX];
	int front,rear;
	public:
		Queue() {
			front=rear=-1;
		}
		int enque(int e)
		{
			if(front==rear)
			{
				front=rear=0;
				queue[rear]=e;
				rear++;
			}
			else if(rear==MAX)
			{
				cout<<"Queue is full\n";
				return 0;
			}
			else{
				queue[rear]=e;
				rear++;
			}
		}
		
		int deque()
		{
			if(front>rear-1)
			{
				cout<<"Queue is Empty\n";
				return 0;
			}
			else{
				front++;
				return (queue[front-1]);
			}
		}
		
		int traverse()
		{
			for(int i=front;i<rear;i++)
			cout<<queue[i]<<" ";
		}
};

int main()
{
	int n=0,e=0;
	Queue q;
	while(1)
	{
		cout<<"1.Enque     2.Deque     3.Traverse      4.Exit\n";
		cin>>n;
		switch(n)
		{
			case 1:
				cin>>e;
				q.enque(e);
				break;
			case 2:
				q.deque();
				break;
			case 3:
				q.traverse();
				break;
			case 4:
				return 0;
			default:
				cout<<"Please choose b/w 1/2/3/4\n";
		}
	}
	
}

