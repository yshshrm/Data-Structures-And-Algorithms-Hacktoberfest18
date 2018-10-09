include<stdlib.h>

struct node
{
	int val, pr;
	struct node *next;
}*start;

void push(int, int);
void pop();

void disp()
{
	struct node *temp;
	temp = start;
	printf("\nPriority Queue: ");
	while(temp!=NULL)
	{
		printf("%d,%d ",temp->val, temp->pr);
		temp=temp->next;
	}
printf("\n");
}

void push(int ele,int pri)
{
	struct node *temp, *t;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->val=ele;
	temp->pr=pri;
	temp->next=NULL;

	if(start==NULL)
		start = temp;
	else if(start->pr>pri)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		t=start;
		while(t->next!=NULL && (t->next)->pr<=pri )
			t=t->next;
		temp->next=t->next;
		t->next=temp;
	}
disp();
}

void del()
{
	if(start!=NULL)
	{
	printf("\n\tRemoved: %d",start->val);
	start = start->next;
	disp();
	}
	else
	printf("\nError List Empty");
}


int main()
{
	int ch, ele, pr, check=1;
while(check==1)
{
	printf("\nIn Priority Queue Select:\n1. Insert\n2. Remove\n3. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter element and its priority: ");
			scanf("%d%d",&ele,&pr);
			push(ele,pr);
			break;
		case 2:
			del();
			break;
		case 3:
			check=0;
			break;
		default:
			printf("Wrong Choice");
	printf("\nPress 1 to continue or 0 to stop");
	scanf("%d",&check);
	}
}
return 0;
}
