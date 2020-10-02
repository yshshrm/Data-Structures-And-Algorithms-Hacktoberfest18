#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *root = NULL;

void display();
void insert(int data,int position);
void create(int n);

int main(){
	int n,data,position;
	printf("Enter the length of the list-");
	scanf("%d",&n);
	create(n);
	printf("Enter the node to be inserted-");
	scanf("%d",&data);
	printf("Enter the position-");
	scanf("%d",&position);
	insert(data,position);
	printf("The final list becomes-\n");
	display();
	return(0);
}

void create(int n){
	struct node *temp, *newNode;
	int data,i;
	
	root = (struct node*)malloc(sizeof(struct node));
	if(root==NULL){
		printf("Unable to allocate memory");
	}
	else{
		printf("Enter data in node 1 -");
		scanf("%d",&data);
		root->data = data;
		root->link = NULL;
		
		temp = root;
		
		for(i=2;i<=n;i++){
			newNode = (struct node*)malloc(sizeof(struct node));
			
			if(newNode==NULL){
			printf("Unable to allocate memory");
			break;}
			
			else{
				printf("Enter the data in node %d -",i);
				scanf("%d",&data);
				
				newNode->data = data;
				newNode->link = NULL;
				
				temp->link = newNode;
				temp = temp->link;
			}
		}
		printf("List created successfully\n");
	}
}

void insert(int data, int position){
	int i;
	struct node *temp,*newNode;
	
	newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode==NULL)
	printf("Unable to allocate");
	
	else{
		newNode->data = data;
		newNode->link = NULL;
		
		temp = root;
		
		for(i=2;i<position;i++){
			temp = temp->link;
			if(temp == NULL)
			break;
		}
		if(temp!=NULL){
			newNode->link = temp->link;
			temp->link = newNode;
			printf("Data inserted successfully\n");
		}
		else{
			printf("Unable to insert");
		}
	}
}

void display(){
	struct node *temp;
	if(root==NULL)
	printf("list empty");
	else{
		temp =root;
		while(temp!=NULL){
			printf("Data = %d \n",temp->data);
			temp = temp->link;
		}
	}
}
