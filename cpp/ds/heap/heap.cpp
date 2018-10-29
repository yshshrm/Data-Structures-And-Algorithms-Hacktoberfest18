//Max Heap
#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void siftup(int a[],int n,int i)			//recursive
{
	if(i<2||a[i]<a[i/2])
		return;
	swap(a[i],a[i/2]);
	siftup(a,n,i/2);
}

void siftdown(int a[],int n,int i)		//recursive
{
	if(2*i>n)
		return;
	if(2*i==n)			//one child
	{
		if(a[i]<a[2*i])
			swap(a[i],a[2*i]);

		return;	
	}

	if(a[i]>a[2*i]&&a[i]>a[2*i+1])
		return;
	else if(a[2*i]>a[2*i+1])
	{
		swap(a[i],a[2*i]);
		siftdown(a,n,2*i);
	}
	else
	{	
		swap(a[i],a[2*i+1]);
		siftdown(a,n,2*i+1);
	}

}


void buildheap(int a[],int n)
{	
	int i;
	for(i=n/2;i>=1;i--)
		siftdown(a,n,i);
}

int extractmax(int a[],int &n)
{
	int temp = a[1];
	a[1] = a[n];
	n--;
	siftdown(a,n,1);
	return temp;
}

void insert(int a[],int &n,int i)
{
	n++;
	a[n] = i;
	siftup(a,n,n);
}

void deleting(int a[],int &n,int temp)
{	
	int i;
	for(i=1;i<=n;i++)
		if(a[i]==temp)
			break;

	if(i!=n+1)
	{
		a[i] = a[n];
		n--;
		siftdown(a,n,i);
	}
}

int main()
{
	int n,i,temp1,temp2;
	cout<<"Enter how many elements : ";
	cin>>n;
	int array[1000];
	for(i=1;i<=n;i++)
	{
		cin>>array[i];
	}
	buildheap(array,n);

	cout<<"The heap is : ";
	for(i=1;i<=n;i++)
		cout<<array[i]<<" ";

	cout<<"How many to insert? : ";
	cin>>temp1;
	for(i=1;i<=temp1;i++)
	{
		cin>>temp2;
		insert(array,n,temp2);
	}
	cout<<"The heap is : ";
	for(i=1;i<=n;i++)
		cout<<array[i]<<" ";

	cout<<"How many to delete? : ";
	cin>>temp1;
	for(i=1;i<=temp1;i++)
	{
		cin>>temp2;
		deleting(array,n,temp2);
	}
	cout<<"The heap is : ";
	for(i=1;i<=n;i++)
		cout<<array[i]<<" ";



}