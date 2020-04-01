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

void reverse(struct node *temp)
{
	if(temp->link == NULL)
	{
	head = temp;            // Exit Condition
	return;
	}
	reverse(temp->link);    // recursion
	struct node *temp1 = temp->link;
	temp1->link = temp;
	temp->link = NULL;	
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
	reverse(head);
	printf("Reversed ");
	print();
}

