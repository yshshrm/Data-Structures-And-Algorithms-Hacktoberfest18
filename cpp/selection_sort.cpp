#include <iostream>
using namespace std;

// perform selection sort on arr[]
void selectionSort(int arr[], int n)
{
	// run (n - 1) times
	for (int i = 0; i < n - 1; i++) 
	{
		// find the minimum element in the unsorted subarray[i..n-1] 
		// and swap it with arr[i]
		int min = i;
		
		for (int j = i + 1; j < n; j++)
		{
			// if arr[j] element is less, then it is the new minimum
			if (arr[j] < arr[min])
				min = j;	// update index of min element
		}

		// swap the minimum element in subarray[i..n-1] with arr[i]
		int temp = arr[i];  //let say arr[i] is 5 and arr[min]=4 so we will store 5 in temp then we will update arr[i] with 4 and then we will store that 5 in arr[min];
		arr[i]=arr[min];//if we don't create temp then the arr[i] will get updated with 4 but tha value stored there i.e 5 will be gone so temp is for temporary holding the value to help in swapping
		arr[min]=temp;  // you can also use swap(arr[min],arr[i]); 
	}
}

// Function to print n elements of the array arr
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// main function
int main()
{
	int n;
	cin>>n; // size of array 
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	selectionSort(arr, n);
	printArray(arr, n);

	return 0;
}
