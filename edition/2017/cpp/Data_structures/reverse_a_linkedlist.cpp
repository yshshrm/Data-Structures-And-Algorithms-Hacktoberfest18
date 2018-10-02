#include <iostream>
using namespace std;
struct node{
	long long int data;
	struct node *next;
};

node* create(int size){
	struct node *start,*temp,*end,*p;
	p=new node;
	temp=start=p;
	cin>>p->data;
	for(int i=1;i<size;i++){
		p=new node;
		temp->next=p;
		cin>>p->data;
		p->next= NULL;
		temp=p;
	}
	end=temp;
	return start;
}
node* rev(node *start){
	node *temp,*ptr,*p;
	p=start;
	temp=ptr=NULL;
	while(p!=NULL){
		temp=p->next;
		p->next=ptr;
		ptr=p;
		p=temp;
	}
	return ptr;
}
void display(node *start){
	node *p,*ptr;
	ptr=p=start;
	cout<<ptr->data<<" ";
	while(ptr->next!=NULL){
		ptr=ptr->next;
		cout<<ptr->data<<" ";
	}
}
int main()
{
    node *p;
    long long int t;
    cin>>t;
    p=create(t);
    p=rev(p);
    display(p);
    return 0;
}

