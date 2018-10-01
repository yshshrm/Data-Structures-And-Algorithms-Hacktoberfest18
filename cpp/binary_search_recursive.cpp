#include<iostream>
using namespace std;

void binsearch(int arr[], int f, int l, int e)
{
	int mid=(f+l)/2;

	if(e==arr[mid])
	{
		cout<<"Element found at index "<<mid<<endl;
		return;
	}
	if(f!=l)	//if one element is not left
	{
		if(e<arr[mid])
			binsearch(arr,f,mid-1,e);	//recurring in left of m
		else if(e>arr[mid])
			binsearch(arr,mid+1,l,e);	//recurring in right of m
	}
	else
		cout<<"Element not found."<<endl;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};	//sorted array
	int n = sizeof(arr)/sizeof(arr[0]);

	int e;
	cout<<"Enter element to find: "; cin>>e;

	binsearch(arr, 0, n-1, e);
}