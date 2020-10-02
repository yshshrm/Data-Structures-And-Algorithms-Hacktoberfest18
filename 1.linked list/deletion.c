#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
 struct node *root;
 
void create(int n);
void display();
void delete_key(int key);


int main(){
	int n,key;
	printf("Enter the length of list-");
	scanf("%d",&n);
	create(n);
	printf("Enter the data to delete");
	scanf("%d",&key);
	delete_key(key);
	printf("The new linked list is-\n");
	display();
}
void create(int n){
	struct node *temp, *newNode;
	int data,i;
	
	root = (struct node*)malloc(sizeof(struct node));
	if(root==NULL){
		printf("Unable to allocate memory");
	}
	else{
		printf("Enter the data in node 1 -");
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

void display(){
	struct node *temp;
		int i=1;
	if(root==NULL){
		printf("List empty\n");
		return;
	}
	
	temp=root;
	while(temp!=NULL){
	
		printf("Data %d - %d\n",i,temp->data);
		temp= temp->link;
		i++;
	}
	printf("\n");
}

void delete_key(int key){
	struct node *prev,*cur;
	while(root!=NULL && root->data==key){
		prev = root;
		root = root->link;
		
		free(prev);
		return;
	}
	
	prev = NULL;
	cur = root;
	
	while(cur!=NULL){
		if(cur->data ==key){
			if(prev != NULL)
			prev->link = cur->link;
			
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->link;
	}
}
