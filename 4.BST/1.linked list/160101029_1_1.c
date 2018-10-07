#include <stdio.h>
#include <stdlib.h>

//structure representing linked list
struct node
{
	char d;
	struct node *next;
};


struct node *head1;			//head pointer for list1
struct node *head2;			//head pointer for list 2



int count1,count2;		//variables to count no. of comparisions



//move to front function
void move_to_front(char alpha)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));		//creating a temporary node
	//storing alpha in temporary node
	temp->d=alpha;	
	temp->next=NULL;


	struct node *curr=head1;			//temporary pointer which points to current node
	struct node *currprev=NULL;			//temporary pointer which points to previous node of current node


	//when list is empty
	if(head1==NULL)
		head1=temp;

	//when first element in list is alpha
	else if(head1->d==alpha)
	{
		count1++;		//incrementing comparision
		return;
	}


	else
	{
		//traversing list starting from head till alpha is found or end of list
		while(curr->d!=alpha && curr->next!=NULL)
		{
			count1++;						//incrementing comparision
			currprev=curr;					//storing previous node
			curr=curr->next;				//updating current node
		}

		//if alpha is last node of the list
		if(curr->d==alpha && curr->next==NULL)
		{
			count1++;						//incrementing comparision

			temp->next=head1;				//adding temp at front
			head1=temp;						//making it as head
			currprev->next=NULL;			//making last node NULL
			free(curr);						//deleting last node
		}

		//if alpha is found in the middle of the list
		else if(curr->d==alpha && curr->next!=NULL)
		{
			count1++;						//incrementing comparisions


			currprev->next=curr->next;		//linking prevs node to next node by skipping current node

			temp->next=head1;				//adding temp at front
			head1=temp;						//making temp as head
			free(curr);						//deleting current node
		}

		//if alpha is not found in the list
		else if(curr->d!=alpha && curr->next==NULL)
		{
			count1++;
			curr->next=temp;				//adding node at the end
		}
	}
}


//Transpose function
void transpose(char alpha)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));		//creating a temporary node

	temp->d=alpha;
	temp->next=NULL;


	struct node *curr=head2;				//temporary pointer which points to current node
	struct node *currprev=NULL;				//temporary pointer which points to previous node of current node

	//when list is empty
	if(head2==NULL)
		head2=temp;

	//when first element in list is alpha
	else if(head2->d==alpha)
	{
		count2++;			//increment comparisions
		return;
	}


	else
	{
		//traversing list starting from head till alpha is found or end of list
		while(curr->d!=alpha && curr->next!=NULL)
		{
			count2++;					//increment comarisions
			currprev=curr;				//storing previous node
			curr=curr->next;			//updating current node
		}

		//if alpha is last node of the list
		if(curr->d==alpha && curr->next==NULL)
		{
			count2++;					//incrementing comparision

			char c;						//temporary variable to swap data

			//swapping previous node data and current node data 
			c=currprev->d;    
			currprev->d=curr->d;
			curr->d=c;
		}

		//if alpha is found in the middle of the list
		else if(curr->d==alpha && curr->next!=NULL)
		{
			count2++;					//incrementing comparisions

			char c;
			//swapping previous node data and current node data
			c=currprev->d;    
			currprev->d=curr->d;
			curr->d=c;
		}

		//if alpha is not found in the list
		else if(curr->d!=alpha && curr->next==NULL)
		{
			count2++;
			curr->next=temp;		//adding temp node at the end
		}
	}
}


//Function to print both lists
void printlists()
{
	struct node *curr=head1;		//temporary pointer which points to current node

	//printing Move To Front List
	printf("MoveToFront\t");
	//traversing through the list and printing
	while(curr!=NULL)
	{
		printf("%c ",curr->d );
		curr=curr->next;
	}

	printf("\t%d\n", count1);		//printing no. of comparisions while creating list1

	curr=head2;

	//printing Transpose list
	printf("Transpose\t");
	//traversing through the list and printing
	while(curr!=NULL)
	{
		printf("%c ",curr->d );
		curr=curr->next;
	}


	printf("\t%d\n",count2);		//printing no. of comparisions while creating list2

}



int main()
{
	head1=NULL;
	head2=NULL;

	//innitializing count variables
 	count1=0;			//comparisions for list 1
 	count2=0;			//comparisions for list 2

	char alpha;			//temporary variable to store scanned data
	printf("Enter space seperated Alphabets and press enter:");
	//taking input and creating list
	while(alpha!='\n')
	{
		scanf("%c",&alpha);
		//skipping the spaces
		if (alpha!=' '&&alpha!='\n')
		{
			move_to_front(alpha);
			transpose(alpha);
		}
	}


	printlists();		//calling function to print lists


	return 0;
}