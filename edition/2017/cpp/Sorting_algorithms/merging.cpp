#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};

node* create(int size){
	struct node *start,*temp,*end,*p;
	p=new node;
	temp=start=p;
	int x;
	cin>>x;
	p->data=x;
	for(int i=1;i<size;i++){
		p=new node;
		temp->next=p;
		cin>>x;
		p->data=x;
		p->next= NULL;
		temp=p;
	}
	end=temp;
	return start;
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

node* merge(node *p,node *s,int n,int m){
	node *ptr,*start;
	if(n>0 and p->data < s->data){
		start=ptr=p;
		p=p->next;
	}
	else if(m>0 and p->data >=s->data){
		ptr=start=s;
		s=s->next;
	}
	else return p;
	int t=n+m-1;
	while(t--){
		if(p==NULL){
			ptr->next=s;
			return start;
		}
		else if(s==NULL){
			ptr->next=p;
			return start;
		}
		else if(s->data<p->data){
			ptr->next=s;
			s=s->next;
			ptr=ptr->next;
		}
		else {
			ptr->next=p;
			p=p->next;
			ptr=ptr->next;
		}
	}
	ptr->next=NULL;
	return start;
}
int main()
{
    int n,m;
    node *p,*s;
    cin>>n;
	p=create(n);
    cin>>m;
	s=create(m);
	p=merge(p,s,n,m);
	display(p);
    return 0;
}
