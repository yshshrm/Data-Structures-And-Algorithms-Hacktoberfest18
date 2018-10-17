#include<stdio.h>
#include<stdlib.h>
struct node
{
	int degree;
	int coeff;
	struct node *next;
};
typedef struct node Node;
void create(Node**);
int count(Node*);
Node* add(Node*,Node*);
void traverse(Node*);
void create(Node **start)
{
	int deg;
	Node *newnode,*prev;
	printf("Enter degree of polynomial\n");
	scanf("%d",&deg);
	while(deg!=-1)
	{
		newnode=(Node *)malloc(sizeof(Node));
		newnode->degree=deg;
		newnode->next=NULL;
		printf("Enter coefficient of x^%d\n",deg);
		scanf("%d",&newnode->coeff);
		if(*start==NULL)
			*start=newnode;
		else
			prev->next=newnode;
		prev=newnode;
		deg--;
	}
}
int count(Node *start)
{
	int c=0;
	while(start!=NULL)
	{
		c++;
		start=start->next;
	}
	return c;
}		
Node* add(Node *start1,Node *start2)
{
	Node *start3=NULL,*newnode,*prev;
	while(start1!=NULL||start2!=NULL)
	{
		if(start1->degree==start2->degree)
		{
			newnode=(Node *)malloc(sizeof(Node));
			newnode->next=NULL;
			newnode->degree=start1->degree;
			newnode->coeff=start1->coeff+start2->coeff;
			if(start3==NULL)
				start3=newnode;
			else
				prev->next=newnode;
			prev=newnode;					
			start1=start1->next;
			start2=start2->next;
		}	
		else
		{
			newnode=(Node *)malloc(sizeof(Node));
			newnode->degree=start1->degree;
			newnode->coeff=start1->coeff;
			newnode->next=NULL;
			if(start3==NULL)
				start3=newnode;
			else
				prev->next=newnode;
			prev=newnode;
			start1=start1->next;
		}
	}
	return start3;
}			
void traverse(Node *start)
{
	while(start!=NULL)
	{
		if(start->coeff!=0)
		{
			printf("%dx^%d",start->coeff,start->degree);
			if(start->next!=NULL)
				printf("+");
		}		
		start=start->next;
	}
	printf("\n");
}	
void main()
{
	Node *start1=NULL,*start2=NULL,*start3;
	int c1,c2;
	create(&start1);
	create(&start2);
	c1=count(start1);
	c2=count(start2);
	if(c1>c2)
		start3=add(start1,start2);
	else
		start3=add(start2,start1);	
	printf("Polynomial 1:\n");
	traverse(start1);
	printf("Polynomial 2:\n");
	traverse(start2);
	printf("Added polynomial:\n");
	traverse(start3);					
}	
