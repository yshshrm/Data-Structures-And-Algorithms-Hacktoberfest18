// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 100001 

// Function to return the minimum 
// absolute difference between any 
// two elements of the array 
int getMinDiff(int arr[], int n) 
{ 
	// To store the frequency of each element 
	int freq[MAX] = { 0 }; 

	for (int i = 0; i < n; i++) { 

		// Update the frequency of current element 
		freq[arr[i]]++; 

		// If current element appears more than once 
		// then the minimum absolute difference 
		// will be 0 i.e. |arr[i] - arr[i]| 
		if (freq[arr[i]] > 1) 
			return 0; 
	} 

	int mn = INT_MAX; 

	// Checking the distance between the nearest 
	// two elements in the frequency array 
	for (int i = 0; i < MAX; i++) { 
		if (freq[i] > 0) { 
			i++; 
			int cnt = 1; 
			while ((freq[i] == 0) && (i != MAX - 1)) { 
				cnt++; 
				i++; 
			} 
			mn = min(cnt, mn); 
			i--; 
		} 
	} 

	// Return the minimum absolute difference 
	return mn; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4 }; 
	int n = sizeof(arr) / sizeof(int); 

	cout << getMinDiff(arr, n); 

	return 0; 
} 
