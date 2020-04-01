#include<stdio.h>
#include<stdlib.h>
struct node 
{
        int info;
        struct node *next;
};
typedef struct node Node;
void create(Node **);
void insert(Node **);
void delete(Node **);
void traverse(Node *);
void count(Node *);
void search(Node *);
void create(Node **start)
{
	int c=1;
	Node *newnode,*prev;
	while(c==1)
	{
		newnode=(Node *)malloc(sizeof(Node));
		printf("Enter info\n");
		scanf("%d",&newnode->info);
		newnode->next=NULL;
		if(*start==NULL)
			*start=newnode;
		else
			prev->next=newnode;
		prev=newnode;
		printf("Enter 1 to create more nodes\nEnter 0 to exit\n");
		scanf("%d",&c);
	}
}
void insert(Node **start)
{
	Node *temp=*start;
	Node *newnode=(Node *)malloc(sizeof(Node));
	printf("Enter number to insert\n");
	scanf("%d",&newnode->info);
	int b;
	printf("Enter 1 to insert according to position\nEnter 2 to insert according to value\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1: ;
			int pos;
			printf("Enter position\n");
			scanf("%d",&pos);
			if(pos==0)
			{
				printf("Node inserted\n");
				newnode->next=*start;
				*start=newnode;
			}
			else
			{
				int p=0;
				while(temp->next!=NULL)
				{
					if((p+1)==pos)
					{
						printf("Node inserted\n");
						newnode->next=temp->next;
						temp->next=newnode;
						return;
					}
					p++;
					temp=temp->next;
				}
				printf("Position does not exist\n");	
			}
			break;
		case 2: ;
			int val;
			printf("Enter value to search\n");
			scanf("%d",&val);
			while(temp!=NULL)
			{
				if(temp->info==val)
				{
					printf("Node inserted\n");
					newnode->next=temp->next;
					temp->next=newnode;
					return;
				}
				temp=temp->next;
			}
			printf("Value not found\n");
			break;
		default:printf("Wrong choice\nNode not inserted\n");
	}
}					
void delete(Node **start)
{
	Node *temp=*start;
	int b;
	printf("Enter 1 to delete according to position\nEnter 2 to delete according to value\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1: ;
			int pos;
			printf("Enter position\n");
			scanf("%d",&pos);
			if(pos==0)
			{
				printf("Node deleted\n");
				*start=(*start)->next;
			}
			else
			{
				int p=1;
				while(temp!=NULL)
				{
					if(p==pos)
					{
						printf("Node deleted\n");
						temp->next=temp->next->next;
						return;
					}
					p++;
					temp=temp->next;
				}
				printf("Position does not exist\n");	
			}
			break;
		case 2: ;
			int val;
			printf("Enter value to search\n");
			scanf("%d",&val);
			if(temp->info==val)
			{
				printf("Node deleted\n");
				*start=(*start)->next;
				return;
			}
			else
			{	
				while(temp->next!=NULL)
				{
					if((temp->next)->info==val)
					{
						printf("Node deleted\n");
						temp->next=temp->next->next;
						return;
					}
					temp=temp->next;
				}
			}	
			printf("Value not found\n");
			break;
		default:printf("Wrong choice\nNode not deleted\n");
	}
}										
void traverse(Node *start)
{
	while(start!=NULL)
	{
		printf("%d ",start->info);
		start=start->next;
	}
	printf("\n");
}						        
void count(Node *start)
{
	int c=0;
	while(start!=NULL)
	{
		c++;
		start=start->next;
	}
	printf("Number of nodes=%d\n",c);
}		
void search(Node *start)
{
	int val;
	printf("Enter value to search\n");
	scanf("%d",&val);
	while(start!=NULL)
	{
		if(start->info==val)
		{
			printf("Value found\n");
			return;
		}	
		start=start->next;
	}	
	printf("Value not found\n");
}
void main()
{
	Node *start=NULL;
	create(&start);
	int choice,loop=1;
	while(loop==1)
	{
		printf("Enter 1 to insert more nodes\nEnter 2 to delete nodes\nEnter 3 to count number of nodes\nEnter 4 to search for nodes\nEnter 5 to traverse node\nEnter 6 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert(&start);
				break;
			case 2:delete(&start);
				break;
			case 3:count(start);
				break;
			case 4:search(start);
				break;
			case 5:traverse(start);
				break;
			case 6:loop=0;
				break;
			default:printf("Wrong choice\n");
		}
	}			
}										       	
