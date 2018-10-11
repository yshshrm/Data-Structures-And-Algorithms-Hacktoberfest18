#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}node;
node* start=NULL;
void insert(){
	int i,m;
	node* t=NULL;
	t=(node*)malloc(sizeof(node));
	node* r=start;
	printf("Enter the position where you want to add the element: ");
	scanf("%d",&m);
	if ((start==NULL)&&(m!=0)){
		printf("Invalid");
	}
	else if ((start==NULL)&&(m==0)){
		printf("Enter data: ");
		scanf("%d",&(t->data));
		start=t;
		start->next=NULL;
		start->prev=NULL;
	}
	else{
		for (i = 0; i < m; i++){
			if (r->next==NULL){
				break;
			}
			r=r->next;
		}
		if(r->next==NULL){
			printf("Enter data: ");
			scanf("%d",&(t->data));
			r->next=t;
			t->prev=r;
		}
		else{
			printf("Enter data: ");
			scanf("%d",&(t->data));
			t->next=r->next;
			((r->next)->prev)=t;
			r->next=t;
			t->prev=r;
		}
	}
}
void delete(){
	int i,m;
	node* r=start;
	printf("Enter the position from where you want to delete the element: ");
	scanf("%d",&m);
	if((start==NULL)&&(m!=0)){
		printf("List is empty\n");
	}
	else if((start!=NULL)&&(m==0)){
		start=start->next;
		start->prev=NULL;
		free(r);
	}
	else{
		for (i = 0; i < m; i++){
			if (r->next==NULL)
				break;
			r=r->next;
		}
		if (r->next==NULL){
			((r->prev)->next)=NULL;
			free(r);
		}
		else{
			((r->prev)->next)=r->next;
			((r->next)->prev)=r->prev;
			free(r);
		}
	}
}
void forward(){
	node* r=start;
	while(r->next!=NULL){
		printf("%d ",r->data);
		r=r->next;
	}
	printf("%d ",r->data);
}
void backward(){
	node* r=start;
	while(r->next!=NULL){
		r=r->next;
	}
	while(r->prev!=NULL){
		printf("%d ",r->data);
		r=r->prev;
	}
	printf("%d ",r->data);
}
void display(){
	int m;
	printf("1. forward order of list\n2. Backward order of list\n");
	scanf("%d",&m);
	switch(m){
		case 1: forward();
				break;
		case 2:	backward();
				break;
		default: printf("invalid\n");
	}
}
void main(){
	int n;
	while(1){
		printf("1. Add a number to the list\n2. Delete a number from the list\n3. View list\n4. Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1: insert();
					break;
			case 2: delete();
 					break;
 			case 3: display();
 					break;
 			case 4: exit(0);
 		    	    break;
 			default : printf("invalid");
		}
	}
}