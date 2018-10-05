#include<stdio.h>
#include<stdlib.h>

int parent(int i)
{
	return (i/2);
}
int left(int i)
{
	return ((2*i)+1);
}
int right(int i)
{
	return ((2*i)+2);
}

struct min_heap
{
	int data;
	int pr;
};

struct min_heap *heap = NULL;
int MaxSize = 0;
int HeapSize = -1;
void insert(struct min_heap *heap, int elem, int pr)
{
	MaxSize++;
	HeapSize++;
	heap[HeapSize].data = elem;
	heap[HeapSize].pr = pr;
	int i = HeapSize;
	while((i>0) && (heap[i].pr < heap[parent(i)].pr))
	{
		long int temp_data = heap[i].data;
		int temp_pr = heap[i].pr;
		heap[i].data = heap[parent(i)].data;
		heap[i].pr = heap[parent(i)].pr;
		heap[parent(i)].data = temp_data;
		heap[parent(i)].pr = temp_pr;
		i = parent(i);
	}
}
void get_min(struct min_heap *heap)
{
	if(HeapSize==-1)
		printf("EMPTY\n");
	else
	{
		printf("%d (%d)\n", heap[0].data, heap[0].pr);
	}		
}
void extract_min(struct min_heap *heap)
{
	if(HeapSize==-1)
		printf("EMPTY\n");
	else
	{
		printf("%d (%d)\n", heap[0].data, heap[0].pr);
		heap[0].data = heap[HeapSize].data;
		heap[0].pr = heap[HeapSize].pr;
		HeapSize--;
		MinHeapify(heap, 0);
	}	
}

void MinHeapify(struct min_heap *heap, int i)
{
	int smallest = i;
	if((left(i) <= HeapSize) && (heap[left(i)].pr < heap[smallest].pr))
		smallest = left(i);
	if((right(i) <= HeapSize) && (heap[right(i)].pr < heap[smallest].pr))
		smallest = right(i);	
	if(smallest!=i)
	{
		int temp_data = heap[i].data;
		int temp_pr = heap[i].pr;
		heap[i].data = heap[smallest].data;
		heap[i].pr = heap[smallest].pr;
		heap[smallest].data = temp_data;
		heap[smallest].pr = temp_pr;
		MinHeapify(heap, smallest);
	}
}
void decrease_priority(struct min_heap *heap, int elem, int pr)
{
	int i;
	for(i=0; i<=HeapSize; i++)
	{
		if(elem == heap[i].data)
		{
			heap[i].pr = pr;
			break;
		}
	}
	while((i>0) && (heap[i].pr < heap[parent(i)].pr))
	{
		int temp_data = heap[i].data;
		int temp_pr = heap[i].pr;
		heap[i].data = heap[parent(i)].data;
		heap[i].pr = heap[parent(i)].pr;
		heap[parent(i)].data = temp_data;
		heap[parent(i)].pr = temp_pr;
		i = parent(i);
	}
}
int main()
{
	int elem, pr;
	char ch;
	label: ch = getchar();
	switch(ch)
	{
		case 'a': heap = (struct min_heap *)realloc(heap, (MaxSize+1)*sizeof(struct min_heap));
			scanf("%d", &elem);
			scanf("%d", &pr);
			insert(heap, elem, pr);
			break;
		case 'e': extract_min(heap);
			break;
		case 'g': get_min(heap);
			break;
		case 'd': scanf("%d", &elem);
			scanf("%d", &pr);
			decrease_priority(heap, elem, pr);
			break;		
	}
	if(ch!='s')
		goto label;
	return 0;
}
