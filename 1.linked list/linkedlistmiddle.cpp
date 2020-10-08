#include<bits/stdc++.h>
using namespace std;

 struct node
 {
 	int data;
 	struct node* next;
 };

void push(node** head, int data){
	node* n = new node();
	n->data = data;
	n->next = *head;
	*head = n;
}

void traverse(node* head){
	int c=0;
	node* p = new node();
	node* q = new node();
	p = head;
	q = head;
	while(q){
		c++;
		q = q->next;
	}
	c = c/2;
	while(c--){
		p = p->next;
	}
	cout<<p->data<<endl;
}

void mid(node* head){
	node* s = new node();
	node* f = new node();
	s = head;
	f = head;
	while(f!=0 && f->next!=0){
		f = f->next->next;
		s = s->next;
	}
	cout<<s->data<<endl;
}

 int main(){
 	#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
     #endif
 	node* head = NULL;
 	push(&head,5);
 	push(&head,4);
 	push(&head,3);
 	push(&head,2);
 	push(&head,1);
 	traverse(head);
 	mid(head);

 	return 0;
 }