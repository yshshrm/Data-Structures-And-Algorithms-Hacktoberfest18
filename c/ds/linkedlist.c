#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

NODE *insertstart(NODE *head,int no)
{
	NODE *q;
	q=(NODE *)malloc(sizeof(NODE));
	q->next=head;
	q->info=no;
	return q;
}

NODE *insertend(NODE *head,int no)
{
	NODE *p=head,*q;
	q=(NODE *)malloc(sizeof(NODE));
	q->info=no;
	q->next=NULL;
	if(head==NULL)
		return q;
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
	return head;
}

NODE *insertbefore(NODE *head,int no,int x)
{
	NODE *p=head,*q;
	q=(NODE *)malloc(sizeof(NODE));
	q->info=no;
	if(head==NULL)
	{
		q->next=NULL;
		return q;
	}
	if(x==-1)
	{
		q->next=head;
		return q;
	}
	if(head->next==NULL||head->info==x)
	{
		q->next=head;
		return q;
	}
	while((p->next)->info!=x)
		p=p->next;
	q->next=p->next;
	p->next=q;
	return head;
}

NODE *insertafter(NODE *head,int no,int x)
{
	NODE *p=head,*q;
	q=(NODE *)malloc(sizeof(NODE));
	q->info=no;
	if(head==NULL)
	{
		q->next=NULL;
		return q;
	}
	while(p->info!=x)
		p=p->next;
	q->next=p->next;
	p->next=q;
	return head;
}

NODE *deletefirst(NODE *head)
{
	NODE *p=head;
	if(head==NULL)
	{
		printf("List is empty:\n");
		return head;
	}
	head=head->next;
	free(p);
	return head;
}

NODE *deletelast(NODE *head)
{
	NODE *p=head;
	if(head==NULL)
	{
		printf("List is empty:\n");
		return head;
	}
	if(p->next==NULL)
	{
		free(p);
		return NULL;
	}
	while((p->next)->next!=NULL)
		p=p->next;
	free(p->next);
	p->next=NULL;
	return head;
}

NODE *del(NODE *head,int x)
{
	NODE *p=head,*q;
	if(head==NULL)
	{
		printf("List is empty:\n");
		return 0;
	}
	if(p->info==x)
	{
		head=p->next;
		free(p);
		return head;
	}
	while(p->info!=x)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
	return head;
}

void display(NODE *head)
{
	if(head==NULL)
		return;
	while(head!=NULL)
	{
		printf("%d ",head->info);
		head=head->next;
	}
	printf("\n");
}

int main()
{
	NODE *head=NULL;
	int choice,pau,ele,x;
	while(1)
	{
		system("cls");
		printf("Linked List\n\nEnter Choice:\n1 Insert Element at the Start:\n2 Insert Element at the End:\n3 Insert Element before an Existing Element:\n4 Insert Element after an Existing Element:\n5 Delete First Element:\n6 Delete Last Element:\n7 Delete Particular Element:\n8 Display Elements:\n9 Exit:\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			system("cls");
			printf("Enter Element:");
			scanf("%d",&ele);
			head=insertstart(head,ele);
			printf("Successfully Added. 0 to return to main menu.");
			scanf("%d",&pau);
		}
		else if(choice==2)
		{
			system("cls");
			printf("Enter Element:");
			scanf("%d",&ele);
			head=insertend(head,ele);
			printf("Successfully Added. 0 to return to main menu.");
			scanf("%d",&pau);
		}
		else if(choice==3)
		{
			system("cls");
			printf("Enter Element and value of x:");
			scanf("%d%d",&ele,&x);
			head=insertbefore(head,ele,x);
			printf("Successfully Added. 0 to return to main menu.");
			scanf("%d",&pau);
		}
		else if(choice==4)
		{
			system("cls");
			printf("Enter Element and value of x:");
			scanf("%d%d",&ele,&x);
			head=insertafter(head,ele,x);
			printf("Successfully Added. 0 to return to main menu.");
			scanf("%d",&pau);
		}
		else if(choice==5)
		{
			system("cls");
			head=deletefirst(head);
			printf("First element successfully Deleted.0 to return to main menu.");
			scanf("%d",&pau);
		}
		else if(choice==6)
		{
			system("cls");
			head=deletelast(head);
			printf("Last element successfully Deleted.0 to return to main menu.");
			scanf("%d",&pau);
		}
		else if(choice==7)
		{
			system("cls");
			printf("Enter element to be deleted:");
			scanf("%d",&ele);
			head=del(head,ele);
			printf("%d successfully Deleted.0 to return to main menu.",ele);
			scanf("%d",&pau);
		}
		else if(choice==8)
		{
			system("cls");
			printf("List is \n");
			display(head);
			printf("0 to return to main menu.");
			scanf("%d",&pau);
		}
		else
			break;
	}
	return 0;
}
