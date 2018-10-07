#include <stdio.h>
#include <stdlib.h>

//structure to store charecters and their priority
struct bob
{
	long int Atime;
	long int Ctime;
};



struct bob *Harray;			//array to store priority heap
long int Hsize;				//size of array at a particular instant

long int Ptime;				//presnt time

//function that returns parent of index i
long int parent(int i)
{
	return (i-1)/2;
}
//heapify a subtree with root i
void heapify(long int i)
{
	//if root element is greater then Heap size
	if(i>Hsize)
		return;


	long int leftC=2*i+1;		//left child index
	long int rightC=2*i+2;		//right child index

	long int small=i;			//smallest priority index

	//if left child is smaller than parent
	if(leftC<Hsize && Harray[leftC].Ctime<=Harray[small].Ctime)
	{
		small=leftC;		//update small index
	}
	//if right child is smaller than parent
	if(rightC<Hsize && Harray[rightC].Ctime<=Harray[small].Ctime)
	{
		small=rightC;		//update small index
	}

		//if smallest is other then the root
	if(small!=i)
	{
		struct bob temp;


		temp=Harray[small];
		Harray[small]=Harray[i];		//swap
		Harray[i]=temp;


		i=small;
		heapify(small);		//call heapify for its child as root
	}
}	


//extract minimum node
void extractMIN()
{
	Harray[0]=Harray[Hsize];
	Hsize--;
	heapify(0);
}
//insert function
void insert(long int A,long int C)
{
	Hsize++;
	long int i=Hsize;
	Harray[Hsize].Atime=A;
	Harray[Hsize].Ctime=C;
	struct bob temp;
	while(i!=0 && Harray[parent(i)].Ctime>Harray[i].Ctime)
	{
		temp=Harray[parent(i)];
		Harray[parent(i)]=Harray[i];
		Harray[i]=temp;
		i=parent(i);
	}
}


int main()
{
	long int N,i,A,C;
	scanf("%ld",&N);
	Harray=(struct bob *)malloc(N*sizeof(struct bob));
	Hsize=-1;
	for(i=0;i<N;i++)
	{
		scanf("%ld %ld",&A,&C);
		insert(A,C);
	}
	long int wait=0;
	Ptime=0;
	for (i = 0; i < N; ++i)
	{

		Ptime+=Harray[0].Ctime;
		wait+=Ptime-Harray[0].Atime;
		extractMIN();
	}
	long int waittime=wait/N;
	printf("%ld\n",waittime);

	return 0;
}