#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int key;
	node* next;
};

node* top=NULL;

int q=0;

int insert(int pos,int data)
{
	node* temp=new node();//temp will bw used to make new node, malloc not needed in c++
	temp->key=data;
	temp->next=NULL;
	if(pos==1)
	{
		node* temp1=new node();
		temp1=top;
		temp->next=temp1;
		top=temp;
		return 0;
	}
	if(pos>q+1)//no of elements<position to be inserted
	{
		cout<<"Insertion not possible\n";
		return 0;
	}
	else if(top==NULL)//list empty
	{
		temp->next=NULL;	
		top=temp;
		return 0;
	}
	
	node* temp1=new node();//for traversing
	temp1=top;//temp1 is 1st node and not top
	for(int i=0;i<pos-2;i++)//n-1 as we need to stop before the pos
		temp1=temp1->next;
	temp->next=temp1->next;//temp1 is currently the node before pos
	temp1->next=temp;
}

int del(int pos)
{
	node* temp=new node();
	temp=top;
	if(pos==1)
	{
		temp=temp->next;
		top=temp;
		return 0;
	}
	for(int i=0;i<pos-2;i++)
		temp=temp->next;
	node* temp1=new node();
	temp1=temp->next;
	temp->next=temp1->next;
}

int traverse()
{
	if(q==0)
	{
		cout<<"List Empty\n";
		return 0;
	}
	node* temp=new node();
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->key<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	int a=0,n=0,b=0;
	while(1)
	{
		cout<<"1.Insert      2.Delete         3.Traverse         4.Exit\n";
		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Enter no to be inserted and position(1 based index)";
				cin>>a>>b;
				insert(b,a);
				q++;
				break;
			case 2:
				cout<<"Enter position to be deleted(1 based index)";
				cin>>a;
				del(a);
				q--;
				break;
			case 3:
				traverse();
				break;
			case 4:
				return 0;
		}
	}
}

