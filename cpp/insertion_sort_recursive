#include <iostream>
using namespace std;

// recursive function to perform insertion sort on subarray arr[i..n]
void insertionSort(int arr[], int i, int n)
{ 
	int value = arr[i];
	int j = i;
	// Find index j within the sorted subset arr[0..i-1]
	// where element arr[i] belongs
	while (j > 0 && arr[j - 1] > value) 
	{
		arr[j] = arr[j - 1];
		j--;
	}
	arr[j] = value;
	// Note that subarray arr[j..i-1] is shifted to
	// the right by one position i.e. arr[j+1..i]

    if (i + 1 <= n)
		insertionSort(arr, i + 1, n);
}

// Function to print n elements of the array arr
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Start from second element (element at index 0 
	// is already sorted)
	insertionSort(arr, 1, n - 1);
	
	// print the sorted array
	printArray(arr, n);

	return 0;
}
