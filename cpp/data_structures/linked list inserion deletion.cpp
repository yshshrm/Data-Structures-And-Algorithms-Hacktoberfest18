#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *link;
};
int main()
{
node *start,*n,*t;
n=new node;
start=n;
t=n;
n->info=20;
t->link=n;
t=t->link;
n=new node;
n->info=30;
t->link=n;
t=n;
n=new node;
n->info=40;
t->link=n;
t=n;
n=new node;
n->info=50;
t->link=n;
t=n;
n->link=NULL;
int ptr;
node *temp=new node;
temp=start;
while(temp!=NULL)
{
	cout<<temp->info<<endl;
	temp=temp->link;
}
cout<<"insertion of a linked list"<<endl;
node *loc=new node;
loc=start;
while(loc!=NULL)
{
	if(loc->info==20)
	{
		break;
	}
	else
	loc=loc->link;
}
n=new node;
n->info=25;
n->link=loc->link;
loc->link=n;

node *temp1=new node;
temp1=start;
while(temp1!=NULL)
{
	cout<<temp1->info<<endl;
	temp1=temp1->link;
}
cout<<"deletion in linked list"<<endl;

node *loc1=new node;
loc1=start;
while(loc1!=NULL)
{
	if(loc1->info==20)
	{
		break;
	}
	else
	loc1=loc1->link;
}
n->info=40;
n->link=loc1->link;
loc1->link=n;

node *temp11=new node;
temp11=start;
while(temp11!=NULL)
{
	cout<<temp11->info<<endl;
	temp11=temp11->link;
}
return 0;
}
