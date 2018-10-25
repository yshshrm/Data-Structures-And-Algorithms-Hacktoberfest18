#include<stdio.h>
#include<stdlib.h>

struct node{
  	int data;
	struct node* link;
	};
struct node* head; //global variable

void InsertAtBeg(int x)
{
 	struct node* temp=(struct node*)malloc(sizeof(struct node)); //node creation
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
	printf("List is Empty!\n"); // underflow condition
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

void reverse()
{
	struct node *present, *prev, *next; // current , previous, next NODE points
	present = head;
	prev = NULL;
	while(present!=NULL)
	{
	next = present->link;
	present->link = prev;
	prev = present;
	present = next;
	}
	head = prev;
}

int main()
{
	head=NULL; //empty list
	printf("How many numbers ?\n");
	int n,i,x;
	scanf("%d",&n);
	printf("Enter the list \n");
	 for(i=0;i<n;i++)
	  {
	    scanf("%d",&x);
            InsertAtBeg(x);
	 }
        print();
	reverse();
	printf("Reversed ");
	print();
}

