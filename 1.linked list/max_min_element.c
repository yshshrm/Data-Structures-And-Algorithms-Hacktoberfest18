#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};
struct node *root=NULL;

void create(int n);
void max_min();

int main(){
	int n;
	printf("Enter the length of list to be created-");
	scanf("%d",&n);
	create(n);
	max_min();
	return 0;
}

void create(int n){
	struct node *temp,*newNode;
	int data,i;
	
	root = (struct node*)malloc(sizeof(struct node));
	if(root==NULL){
		printf("Unable to allocate");
		return;
	}
	else{
		printf("Enter the data in node 1 - ");
		scanf("%d",&data);
		root->data = data;
		root->link = NULL;
		
		temp = root;
		
		for(i=2;i<=n;i++){
			newNode = (struct node*)malloc(sizeof(struct node));
			
			if(newNode==NULL){
			
			printf("Unable to allocate");
			return;}
			else{
				printf("\nEnter the data in node %d - ",i);
			    scanf("%d",&data);
			    newNode->data = data;
			    newNode->link = NULL;
			
			  temp->link  =newNode;
			  temp = temp->link;
			
		}
	}
	printf("List created\n");
}
}

void max_min(){
	struct node *ptr;
	int flag = 1;
	int max, min;
	
	ptr = root;
	
	while(ptr!=NULL){
		if(flag==1){
			max = ptr->data;
			min = ptr->data;
			flag= 0;
		}
		else{
			if(max<ptr->data){
				max = ptr->data;
			}
			if(min>ptr->data){
				min = ptr->data;
			}
		}
		ptr = ptr->link;
	}
   printf("The maximun element is - %d",max);
   printf("\n The minimun element is - %d",min);
}

