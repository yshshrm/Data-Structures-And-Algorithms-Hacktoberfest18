#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//structure to store charecters and their priority
struct queue{
	char data;
	int priority;
};


struct queue *Harray;		//array to store priority heap
int Hsize;					//size of array at a particular instant


//function that returns parent of index i
int parent(int i)
{
	return (i-1)/2;
}

//heapify a subtree with root i
void heapify(int i)
{
	//if root element is greater then Heap size
	if(i>Hsize)
		return;


	int leftC=2*i+1;		//left child index
	int rightC=2*i+2;		//right child index


	int small=i;			//smallest priority index


	//if left child is smaller than parent
	if(leftC<Hsize && Harray[leftC].priority<=Harray[small].priority)
	{
		small=leftC;		//update small index
	}


	//if right child is smaller than parent
	if(rightC<Hsize && Harray[rightC].priority<=Harray[small].priority)
	{
		small=rightC;		//update small index
	}


	//if smallest is other then the root
	if(small!=i)
	{
		struct queue temp;

		//swapping small index and i index
		temp.data=Harray[small].data;
		Harray[small].data=Harray[i].data;
		Harray[i].data=temp.data;

		temp.priority=Harray[small].priority;
		Harray[small].priority=Harray[i].priority;
		Harray[i].priority=temp.priority;


			
		heapify(small);		//call heapify for its child as root
	}
}


//extract minimum node
char extractMIN(int capacity)
{
	char root=Harray[0].data;		//store data in temp variable

	Harray[0]=Harray[Hsize];		//change root item with last element of heap

	Hsize--;						//decrease size of heap
	heapify(0);
	
	return root;					//return minimum
}


//insert function
void insert(char d,int capacity)
{
	Hsize++;			//increase heap size
	
	//if heap size = capacitity
	if(Hsize==capacity)
		return ;


	int i;
	int p=1;

	//calculating priority
	for(i=0;i<Hsize;i++)
	{
		if(Harray[i].data==d)
			p++;
	}

	//inserting at last
	Harray[Hsize].data=d;
	Harray[Hsize].priority=p;

	i=Hsize;
	struct queue temp;

	//running while loop to satisfy the heap property
	while(i!=0 && Harray[parent(i)].priority>Harray[i].priority)
	{
		temp=Harray[parent(i)];
		Harray[parent(i)]=Harray[i];		//SWAPPING 
		Harray[i]=temp;

		i=parent(i);		//updating i
	}
	
}
int main()
{
	char string[50];

	//taking input string
	scanf("%s",string);

	int capacity=strlen(string);	//capacity of heap

	Harray=(struct queue *)malloc(capacity*sizeof(struct queue));	//allocating memory

	Hsize=-1;	//initialising heap size


	int i;

	//inserting string in heap
	for(i=0;i<capacity;i++)
	{
		insert(string[i],capacity);
	}
	
	//storing back in string in required order
	for(i=0;i<capacity;i++)
	{
		string[i]=extractMIN(capacity);
	}

	//printing string
	printf("%s\n",string);
	
	return 0;
}