#include<stdio.h>
#include<stdlib.h>
void create(int n);
void display();
void make_loop(int k);
struct node {
	int data;
	struct node *link;
};
struct node *root = NULL;
void make_loop(int k){
	struct node *temp = root;
	int count = 1;
	while(count<k){
		temp = temp->link;
		count++;
	}
	
	struct node *joint_point = temp;
	
	while(temp->link != NULL){
		temp = temp->link;
	}
	temp->link = joint_point;
}
int main(){
	int n,k;
    scanf("%d",&n);
    create(n);
    printf("Enter the position to \at which you wanna make a loop-");
    scanf("%d",&k);
    make_loop(k);
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
