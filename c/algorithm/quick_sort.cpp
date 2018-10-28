#include <bits/stdc++.h>

using namespace std;


int partition(int arr[],int start, int end);
void quick_start(int arr[], int start,int end)
{
	if(start<end)
	{
		int pi = partition(arr,start,end);

		quick_start(arr,start,pi-1);
		quick_start(arr,pi+1,end);
	}
}

void swap(int &a,int &b)
{
	int temp;

	temp=a;
	a=b;
	b=temp;

}
int partition(int arr[],int start, int end)
{
	int pivot=arr[end];

	int i_index = start;

	for(int i = start; i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i_index],arr[i]);
			i_index+=1;
		}
	}
	swap(arr[i_index],arr[end]);
	// for (int i = 0; i <= end; ++i)
	// {
	// 	cout<<arr[i]<<" ";
	// }
	// printf("\n");

	return i_index;

}
int main()
{
	int n;

	cin>>n;

	int arr[n+1];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	// partition(arr,0,n-1);

	quick_start(arr,0,n-1);

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}

}