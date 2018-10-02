#include <stdio.h>
#include <iostream>

// A recursive binary search algorithm.
// It returns location of x in a given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == x)  return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}


int search(int* arr, int x){
	int n = sizeof(arr) / sizeof(arr[0]);
	return binarySearch(arr, 0, n, x);
}


int main(void)
{
	int arr[] = {2, 3, 4, 10, 40};
	int x = 3;
	int result = search(arr, x);
	(result == -1) ? printf("Element is not present in array")
		: printf("Element is present at index %d \n", result);
	system("pause");
	return 0;
}