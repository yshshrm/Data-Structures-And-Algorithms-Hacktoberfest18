#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* Start=NULL;																																																																																																																																																																																																																																																																																				
void insert(){
	int i,m,count=0;
	struct node* t=NULL;
	t=(struct node*)malloc(sizeof(struct node));
	
	struct node* x=NULL;
	struct node* z=NULL;
	printf("Enter the position where you want to insert the element: ");
	scanf("%d",&m);
	
	if((Start==NULL)&&(m!=0))
		printf("invalid\n");
	else if((Start==NULL)&&(m==0)){
		printf("Enter data: ");
		scanf("%d",&(t->data));
		Start=t;
		t->next=NULL;
	}
	else if((Start!=NULL)&&(m==0)){
		printf("Enter data: ");
		scanf("%d",&(t->data));
		t->next=Start;
		Start=t;
	}
	else{
		x=Start;
		for (i = 0; i < m-1; i++){
			if (x->next==NULL){
				break;
			}
			x=x->next;
		}
		if (x->next==NULL){
				printf("Enter data: ");
				scanf("%d",&t->data);
				x->next=t;
				t->next=NULL;
		}
		else{
				printf("Enter data: ");
				scanf("%d",&t->data);
				z=x->next;
				x->next=t;
				t->next=z;
		}
	} 
}
void delete(){
	int c,i;
	struct node* temp=Start;
	struct node* b=NULL;
	printf("Enter the position from where you want to delete the element\n");
	scanf("%d",&c);
	if(Start==NULL)
		printf("List is empty\n");
	else if((Start!=NULL)&&(c==0)){
		b=Start;
		Start=b->next;
		free(b);
	}
	else{
		for(i=0;i<c;i++){
			if (temp->next==NULL){
				return;
			}
			b=temp;
			temp=temp->next;
		}
		if(temp->next==NULL){
			b->next=NULL;
			free(temp);
		}
		else{
			b->next=temp->next;
			free(temp);
		}
	}
}
void display(){
	struct node* temp=Start;
	if(temp==NULL)
		printf("List is empty\n");
	else{
		while(temp!=NULL){
			printf("%d ",temp->data);
 			temp=temp->next;
		}
		printf("\n");
	}
}
void reverselist(){
	struct node *t=Start;
	struct node *t1=t->next;
	struct node *t2=t1->next;
	Start->next=NULL;
	while(t2!=NULL){
		t1->next=t;
		t=t1;
		t1=t2;
		t2=t1->next;
	}
	t1->next=t;
	Start=t1;
}
void sortlist(){
	struct node *t1=Start;
	struct node *t2=t1->next;
	struct node *t=NULL;
	int flag=1;
	while(flag){
		t=t1;
		flag=0;
		while(t2!=NULL){
			if (t1!=Start){
				if (t1->data>t2->data){
					t1->next=t2->next;
					t->next=t2;
					t2->next=t1;
					t=t2;
					t2=t1->next;
					flag=1;
				}
				else{
					t=t->next;
					t1=t1->next;
					t2=t2->next;
				}
			}
			else{
				if (t1->data>t2->data){
					Start=t2;
					t1->next=t2->next;
					t2->next=t1;
					t2=t2->next;
					t=Start;
					flag=1;
				}
				else{
					t1=t1->next;
					t2=t2->next;
				}
			}
		}
		/*if(t1->data>t2->data){
			t1->next=NULL;
			t->next=t2;
			t2->next=t1;
			t1=Start;
			t2=t1->next;
		}
		else{
			t1=Start;
			t2=t1->next;
		}*/
		t1=Start;
        t2=t1->next;
	}
}
void findbyvalue(){
	int a,count=1;
	struct node* temp=Start;
	printf("Enter the value you want to check if it is in the list or not: ");
	scanf("%d",&a);
	while(temp->next!=NULL){
		if (temp->data==a){
			break;
		}
		else{
			temp=temp->next;
			count++;
		}
	}
	if(temp->data==a)
		printf("Value given by you is in the list and the number at which this entry is present is: %d\n",count);
	else
		printf("Given entry is not in the list\n");
}
int main(){
	int ch;
	while(1){
 		printf("1. Add a number to the list\n2. Delete element of the list\n3. View list\n4. Find a value in the list\n5. Sort list\n6. Reverse the list\n7. Exit\n");
        scanf("%d",&ch);
 		switch(ch){
 			case 1: insert();
 			        break;
 			case 2: delete();
 					break;
 			case 3: display();
 					break;
 			case 4: findbyvalue();
 			        break;
 			case 5: sortlist();
 			        break;
 			case 6:	reverselist();
 					break;
 			case 7:	exit(0);
 					break;
 			default : printf("invalid");
 			}
	}
	return 0;
}