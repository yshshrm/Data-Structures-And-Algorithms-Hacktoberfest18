#include<iostream>
using namespace std;

void swap(int* a, int* b)	//Swaps two elements of array
{
	int t=*a;
	*a=*b;
	*b=t;
}

int main(){
// {
// 	int  arr[] = {5,2,4,8,9,1,3,10,6,7};
// 	int n = sizeof(arr)/sizeof(arr[0]);
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
	cin>>arr[i];
}

	int j,k;
	for(int i=0;i<n;i++)
	{
		k=i;	//Current element
		j=k+1;	//Element after current

		/*
		The following block keeps swapping elements
		And keeps going backward
		If current is higher than next one
		Till current element is the 1st element
		*/
		while(arr[j]<arr[k] && k>=0)
		{
			// swap(&arr[j], &arr[k]);
			int temp=arr[j];
	arr[j]=arr[k];        //We are meaking temp as a temporary container to store the value for some time like if we have arr[j]=7 and arr[k]=6 to swap them if we store arr[j] = arr[k]; then the arr[j] will get the value 6 but after that the value which arr[j] had i.e 7 will be completely gone 
	arr[k]=temp;
			j--;
			k--;
		}
	}

	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}