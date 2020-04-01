#include<stdio.h>
#include<stdlib.h>

struct node{
  	int data;
	struct node* link;
	};
struct node* head; //global variable, can be accessed to everywhere

void insert(int x)
{
 	struct node* temp=(struct node*)malloc(sizeof(struct node)); // here we creating a node.
 	temp->data=x;
	temp->link=NULL; 	 
	if(head != NULL)
  	 {
  	  temp->link=head;
  	 }
	head=temp;
}

void print()
{
	struct node* temp=head;
	if(head == NULL)
	{	
	printf("List is Empty!\n");
	return;
	}
	printf("List is: ");
	 while(temp!=NULL)
	  {
	   printf(" %d",temp->data);
	   temp=temp->link;
	  }
	printf("\n");
}

int main()
{
	head=NULL; //empty list
	printf("How many numbers ?\n");
	int n,i,x;
	scanf("%d",&n);
	 for(i=0;i<n;i++)
	  {
	    printf("Enter the number \n");
	    scanf("%d",&x);
            insert(x);
	    print();
	 }
}
