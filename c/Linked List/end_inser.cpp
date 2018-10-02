#include<stdio.h>
#include<stdlib.h>
using namespace std;

	struct node{
		int data;
		struct node *next;
	};
	struct node *head=NULL;
	void create() {
		int x;
		char ch='Y';
		struct node *cpt;
		while(ch=='Y'||ch=='y') {
		printf("Enter the Data to be Entered\n");
		scanf("%d",&x);
		struct node *ptr=(struct node *)malloc(sizeof(struct node));
		ptr->data=x;
		if(head==NULL)
		{
		head=ptr;
		ptr->next=NULL;}
		else {
			ptr->next=head;
			head=ptr;
		}
		
		printf("Enter more elements?(Y/N)");
		fflush(stdin);
		scanf("%c",&ch);
	}
}
	
	void display() {
		struct node *cpt;
		cpt=head;
		while(cpt!=NULL) {
		printf("%d",cpt->data);
		cpt=cpt->next;
		}
	}
     void reverse(struct node *cpt) {
		if(cpt->next==NULL) {
			head=cpt;
			return;
		
		}
		reverse(cpt->next);
		struct node *ptr=cpt->next;;
		ptr->next=cpt;
		cpt->next=NULL;
		
	}
	void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data; 
        newNode->next = NULL; 

        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; 

        printf("DATA INSERTED SUCCESSFULLY\n");
    }


	
	int main() {
		int x;
		printf("Enter the link list\n");
		create();
		printf("Entered linked list is:\n");
		display();
		fflush(stdin);
		printf("\nEnter the element to be inserted:\n");
		scanf("%d",&x);
		insertNodeAtEnd(x);
		display();
		printf("\nReversed linked list is:\n");
		reverse(head);
		display();
	}



