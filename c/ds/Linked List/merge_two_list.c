#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node *p = NULL;
struct node *q = NULL;
struct node*newhead = NULL;
void insert_1(int x)
{
	struct node*temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data = x;
	temp1->next = NULL;
	if(p == NULL)
	{
		p = temp1;
		return;
	}
	temp1->next = p;
	p = temp1;
}
void insert_2(int x)
{
	struct node*temp2 = (struct node*)malloc(sizeof(struct node));
	temp2->data = x;
	temp2->next = NULL;
	if(q == NULL)
	{
		q = temp2;
		return;
	}
	temp2->next = q;
	q = temp2;
}
void merge()
{
	struct node*s1 = p;
	struct node*s2 = q;
	struct node*s3;
	if(s1->data <= s2->data)
	{
		s3 = s1;
		s1 = s3->next;
	}
	else
	{
		s3 = s2;
		s2 = s3->next;
	}
	newhead = s3;
	while(s1 && s2)
	{
		if(s1->data <= s2->data)
		{
			s3->next = s1;
			s3 = s1;
			s1 = s3->next;
		}
		else
		{
			s3->next = s2;
			s3 = s2;
			s2 = s3->next;
		}
	}
	if(s1 == NULL)
		s3->next = s2;
	if(s2 == NULL)
		s3->next = s1;
}
void display()
{
	struct node*temp = newhead;
	printf("List in sorted order\n");
	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}
int main()
{
	int i;
	int x;
	printf("Enter for list 1\n");
	for(i = 0;i<5;i++)
	{
		scanf("%d",&x);
		insert_1(x);
	}
	printf("Enter for list 2\n");
	for(i = 0;i<5;i++)
	{
		scanf("%d",&x);
		insert_2(x);
	}
	merge();
	display();
}


