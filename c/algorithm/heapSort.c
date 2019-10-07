

#include<stdio.h>
#include<stdlib.h>

#define item int

typedef struct
{
	item *a;
	int rear,size;
}Q;

void init(Q *q, int n)
{
	q->rear=-1;
	q->size=n;
	q->a = (item *)malloc(n*(sizeof(item)));
}

void swap(item *a, item *b)
{
	item t;
	
	t=*a;
	*a=*b;
	*b=t;
}


void CreateHeap(int a[], int n)
{
	int i,c,p;
	
	for(i=1;i<n;i++)
	{
		c=i;
		while(c!=0)
		{
			p=(c-1)/2;
			if(a[p]<a[c])
				swap(&a[p],&a[c]);
			else
				break;
			c=p;
		}
	}
}


void SortHeap(int a[], int n)
{
	int i;
	for(i=n-1;i>=1;i--)
	{
		swap(&a[i], &a[0]);
		CreateHeap(a,i);
	}
}



int main()
{
	Q q;
	
	int n,i;
	
	/*FILE *fptr;
	
	if((fptr = fopen("input.txt","r")) == NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}*/
	
	printf("Enter the number of elements:");
	scanf("%d", &n);
	
	init(&q,n);
	
	printf("Enter the elements to be sorted:");	
	for(i=0;i<n;i++)
		scanf("%d", &q.a[i]);
		
	printf("Elements of the unsorted Priority Queue: ");
	for(i=0;i<n;i++)
		printf("%d ", q.a[i]);
	printf("\n");

	CreateHeap(q.a,n);
	SortHeap(q.a,n);
	
	printf("The elements after sorting are:");
	
	for(i=0;i<n;i++)
		printf("%d ", q.a[i]);
		
	printf("\n\n");
return 0;
	
}







