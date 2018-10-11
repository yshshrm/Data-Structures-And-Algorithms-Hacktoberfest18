#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* last=NULL;
void display(){
	node* r=last;
	if(last==NULL)
		printf("List is empty\n");
	else{
		/*do{
			r=r->next;
			printf("%d ",r->data);
		}while(r!=last);*/
		r=r->next;
		while(r!=last){
			printf("%d ",r->data);
			r=r->next;
		}
		printf("%d\n",r->data);
	}
}
void insert(){
	int n,i;
	node* r=NULL;
	node* e=last;
	node* t=NULL;
	r=(node*)malloc(sizeof(node));
	printf("Enter the position where you want to insert the element: ");
	scanf("%d",&n);
	if((last==NULL)&&(n!=0))
		printf("Invalid\n");
	else if((last==NULL)&&(n==0)){
		printf("Enter data: ");
		scanf("%d",&(r->data));
		last=r;
		last->next=r;
	}
	else if ((n==0)&&(last!=NULL)){
		printf("Enter data: ");
		scanf("%d",&(r->data));
		r->next=e->next;
		e->next=r;
	}
	else{
		for(i=0;i<n;i++){
			e=e->next;
			if (e->next==last)
			{
				break;
			}
		}
		if (e->next==last){
			printf("Enter data: ");
			scanf("%d",&(r->data));
			r->next=e->next;
			e->next=r;
			last=r;
		}
		else{
			printf("Enter data: ");
			scanf("%d",&(r->data));
			t=e->next;
			e->next=r;
			r->next=t;
		}
	}	
}
void delete(){
	int i,a;
	node* r=last->next;
	node* temp=last;
	printf("Enter the entry you want to delete: ");
	scanf("%d",&a);
	while(r->next!=last){
		if (r->data==a){
			temp->next=r->next;
			free(r);
		}
		else{
			temp=r;
			r=r->next;
		}
	}
	if (last->data==a){
		last=r;
		r=r->next;
		last->next=r->next;
		free(r);
	}
	else
		printf("Given entry is not in the list\n");

}
int main(){
	int n;
	while(1){
		printf("1. Add a element to the list\n2. Remove a element from the list\n3. View list\n4. Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:	insert();
					break;
			case 2:	delete();
					break;
			case 3: display();
					break;
			case 4: exit (0);
					break;
			default: printf("Invalid");
		}
	}
	return 0;
}