#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* front;
	node* back;
};

node* top=NULL;

int q=0;

int insert(int pos,int k)
{
	node* temp=new node();
	temp->data=k;
	temp->front=NULL;
	temp->back=NULL;
	if(top==NULL)
	{
		top=temp;
		return 0;
	}
	else if(pos==1)
	{
		temp->back=top;
		top=temp;
		return 0;
	}
	node* temp1=new node();
	temp1=top;
	for(int i=0;i<pos-2;i++)
		temp1=temp1->back;
	node* temp2=temp1;
	temp2=temp2->back;
	temp->front=temp1;
	temp->back=temp2;
	temp1->back=temp;
	if(temp2!=NULL)
	temp2->front=temp;
	return 0;
}

int del(int pos)
{
	node* temp = new node();
	temp=top;
	if(top==NULL)
	{
		cout<<"List Empty\n";
		return 0;
	}
	else if(pos==1&&temp->back==NULL)
	{
		top=NULL;
		return 0;
	}
	else if(pos==1)
	{
		temp=temp->back;
		temp->front=NULL;
		top=temp;
		return 0;
	}
	node* temp1=new node();
	temp1=top;
	for(int i=0;i<pos-2;i++)
		temp1=temp1->back;
	temp=temp1->back;
	if(temp->back==NULL)
	{
		temp1->back=NULL;
		return 0;
	}
	temp=temp->back;
	temp1->back=temp;
	temp->front=temp1;
	return 0;
}

int traverse()
{
	node* temp=new node();
	temp=top;
	if(top==NULL)
	{
		cout<<"List Empty";
		return 0;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->back;
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
				cout<<"Enter no to be inserted and position(1 based index)\n";
				cin>>a>>b;
				insert(b,a);
				q++;
				break;
			case 2:
				cout<<"Enter position to be deleted(1 based index)\n";
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
