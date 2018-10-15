#include <iostream>
using namespace std;

void quickSort(int[], int, int);
int partition(int[], int, int);
void sortFirstMiddleLast(int[], int, int, int);
void swap(int*, int*);

const int MAX = 50;

void quickSort(int anArray[], int first, int last) {
	if (first < last) {
		int pivotIndex = partition(anArray, first, last);	// Partition the array and get the correct pivotIndex

		quickSort(anArray, first, pivotIndex - 1);	// Call quickSort on the partition smaller than pivot
		quickSort(anArray, pivotIndex + 1, last); // Call quickSort on the partition greater than pivot
	}
}

int partition(int anArray[], int first, int last) {
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(anArray, first, mid, last);
	swap(&anArray[mid], &anArray[last - 1]); // Puts mid at the end as the pivot point
	int pivotIndex = last - 1;
	int pivot = anArray[pivotIndex];

	// Sets first values for the loop to check
	int leftIndex = first + 1; // Plus 1 because first was already sorted
	int rightIndex = last - 2; // Minus 2 because last was sorted and pivot is in last - 1

	bool done = false;
	while (!done) {
		// Sets leftIndex to the first value from the left that is greater than pivot
		while (anArray[leftIndex] < pivot) {
			leftIndex++;
		}

		// Sets rightIndex to the first value from the right that is less than pivot
		while (anArray[rightIndex] > pivot) {
			rightIndex--;
		}

		// Swaps the two found values and sets the loop up for the next run
		if (leftIndex < rightIndex) {
			swap(&anArray[leftIndex], &anArray[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
		else
			done = true;
	}
	// Puts pivot in the correct position
	swap(&anArray[leftIndex], &anArray[last - 1]);
	return leftIndex; // Returns the pivot position
}

// Properly sorts the first, middle, and last entries in an array
void sortFirstMiddleLast(int anArray[], int first, int mid, int last) {
	if (anArray[first] > anArray[mid]) {
		swap(&anArray[first], &anArray[mid]);
	}
	if (anArray[mid] > anArray[last]) {
		swap(&anArray[mid], &anArray[last]);
	}
	if (anArray[first] > anArray[mid]) {
		swap(&anArray[first], &anArray[mid]);
	}
}

// Function that swaps two values
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int arr[MAX], n;
	cout << "Enter number of elements:" << endl;
	cin >> n;
	cout << "Enter elements:" << endl;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n - 1);
	cout << "\nArray after sorting:";

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}