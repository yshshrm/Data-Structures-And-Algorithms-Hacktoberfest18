#include<stdio.h>
#include<malloc.h>
int queue[10];
struct node
{
	int data;
	struct node*link;
}*front=NULL,*rear=NULL,*temp=NULL;
void create(int item)
{
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=item;
	p->link=NULL;
	if(front==NULL)
	{
		front=p;
		rear=p;
	}
	else
	{
		rear->link=p;
		rear=p;
	}
}
void display()
{
	if(front==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		temp=front;
		while(temp->link!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
		printf("%d",temp->data);
	}
}
void insert()
{
	int a;
	printf("enter new element : ");
	scanf("%d",&a);
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=a;
	p->link=NULL;
	rear->link=p;
	rear=p;	
}
void deletion()
{
	int del;
	del=front->data;
	front=front->link;
	printf("Deleted item =%d",del);
}
int main()
{
	int selection;
	label:
	printf("\nEnter 1 for creation\n");
	printf("Enter 2 for display\n");
	printf("Enter 3 for insertion\n");
	printf("Enter 4 for deletion\n");
	printf("Your choice : ");
	scanf("%d",&selection);
	if(selection==1)
	{
		int i,item;
		printf("Enter elements\n");
		for(i=0;i<5;i++)
		{
			scanf("%d",&item);
			create(item);
		}
		goto label;
	}
	if(selection==2)
	{
		display();
		goto label;
	}
	if(selection==3)
	{
		insert();
		goto label;
	}
	if(selection==4)
	{
		deletion();
		goto label;
	}
}
