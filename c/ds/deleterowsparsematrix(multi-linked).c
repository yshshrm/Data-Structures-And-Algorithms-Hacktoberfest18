#include<stdio.h>
#include<stdlib.h>

struct mlnode
{
	int row,col,val;
	struct mlnode *nextrow,*nextcol;
};

typedef struct mlnode MLNODE;
int count=0;

void create(MLNODE *head,int r,int c)
{
	int i;
	MLNODE *p=head,*q;

	for(i=0;i<r;i++)
	{
		q=(MLNODE *)malloc(sizeof(MLNODE));
		q->row=i;
		q->col=-1;
		q->nextcol=q;
		p->nextrow=q;
		p=q;
		count++;
	}
	p->nextrow=head;
	p=head;
	for(i=0;i<c;i++)
	{
		q=(MLNODE *)malloc(sizeof(MLNODE));
		q->row=-1;
		q->col=i;
		q->nextrow=q;
		p->nextcol=q;
		p=q;
		count++;
	}
	p->nextcol=head;
}

MLNODE *above(MLNODE *head,int r,int c)
{
	MLNODE *p=head->nextcol,*q;
	while(p->col!=c)
		p=p->nextcol;

	do{
		q=p;
		p=p->nextrow;
	}while(p->row<r && p->row!=-1);
	return q;
}

MLNODE *left(MLNODE *head,int r,int c)
{
	MLNODE *p=head->nextrow,*q;
	while(p->row!=r)
		p=p->nextrow;
	do{
		q=p;
		p=p->nextcol;
	}while(p->col<c && p->col!=-1);
	return q;
}

void insert(MLNODE *head,int r,int c,int x)
{
	MLNODE *q,*a,*l;
	q=(MLNODE *)malloc(sizeof(MLNODE));
	q->row=r;
	q->col=c;
	q->val=x;

	a=above(head,r,c);
	l=left(head,r,c);
	q->nextrow=a->nextrow;
	q->nextcol=l->nextcol;
	a->nextrow=q;
	l->nextcol=q;
}

int delete(MLNODE *head,int r,int c)
{
	MLNODE *p,*a,*l;
	int x;

	a=above(head,r,c);
	l=left(head,r,c);

	p=a->nextrow;
	x=p->val;

	l->nextcol=p->nextcol;
	a->nextrow=p->nextrow;
	free(p);
	return x;
}

void deleterow(MLNODE *head,int x)
{
	MLNODE *p=head,*q,*r;
	while(p->row!=x)
	{
		r=p;
		p=p->nextrow;
	}
	p=p->nextcol;
	while(p->col!=-1)
	{
		delete(head,p->row,p->col);
		p=p->nextcol;
	}
	p=p->nextrow;
	q=p;
	while(p->row!=-1)
	{
		do
		{
			q->row=q->row-1;
			q=q->nextcol;
		}while(q->col!=-1);
		p=p->nextrow;
	}
	p=r->nextrow;
	r->nextrow=p->nextrow;
	free(p);
}
	

void display(MLNODE *head)
{
	MLNODE *p=head->nextrow,*q;
	while(p!=head)
	{
		q=p->nextcol;
		while(q!=p)
		{
			printf("%d ",q->val);
			q=q->nextcol;
		}
		printf("\n");
		p=p->nextrow;
	}
}

int main()
{
	int r,c,ch,m,n,x;
	MLNODE *head=(MLNODE *)malloc(sizeof(MLNODE));
	head->row=-1;
	head->col=-1;
	head->nextcol=head;
	head->nextrow=head;
	count++;

	printf("Enter the dimensions of sparse matrix\n");
	scanf("%d %d",&m,&n);
	create(head,m,n);
	//printf("%d\n",count);

	while(1)
	{
		printf("1.Insert a non-zero element into the matrix\n2.Delete an element from the matrix\n3.Display the matrix\n4.Delete a row\n5.Exit\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
			        printf("Enter the location on which you want to insert(x,y,val)\n");
			        scanf("%d %d %d",&r,&c,&x);
			        insert(head,r,c,x);
			        break;
			case 2:
			        printf("Enter the location from which you want to delete(x,y)\n");
			        scanf("%d %d",&r,&c);
			        printf("Element deleted = %d",delete(head,r,c));
			        break;
			case 3:
			        display(head);
			        break;
			case 4: 
				printf("Enter the row number you want to delete\n");
				scanf("%d",&x);
				deleterow(head,x);
				break;
			case 5: 
			        exit(0);
			default:
			         printf("Invalid choice\n");                                        
		}
	}
	return 0;
}

