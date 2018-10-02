// Java program for implementation of QuickSort 
class QuickSort {
	/*
	 * This function takes last element as pivot, places the pivot element at its
	 * correct position in sorted array, and places all smaller (smaller than pivot)
	 * to left of pivot and all greater elements to right of pivot
	 */
	int partition(int arr[], int si, int ei) {
		int pivot = arr[si];
		int i = (si - 1); // index of smaller element
		for (int j = si; j < ei; j++) {
			
			if (arr[j] <= pivot) {
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		// swap arr[i+1] and arr[ei] (or pivot)
		int temp = arr[i + 1];
		arr[i + 1] = arr[ei];
		arr[ei] = temp;
		
		return i + 1;
	}

	/*
	 * The main function that implements QuickSort() arr[] --> Array to be sorted,
	 * si --> Starting index, ei --> Ending index
	 */
	void sort(int arr[], int si, int ei) {
		
		if (si < ei) {
			
			int pi = partition(arr, si, ei);

			// Recursively sort elements before
			// partition and after partition
			sort(arr, si, pi - 1);
			sort(arr, pi + 1, ei);
		}
	}

	/* A utility function to print array of size n */
	static String printArray(int arr[]) {
		String s = "[ ";
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			s += (arr[i] + " ");
		return s+']';
	}

	// Driver program
	public static void main(String args[]) {
		int arr[] = { 2,1,4,3,6,5 };
		int n = arr.length;

		QuickSort ob = new QuickSort();
		ob.sort(arr, 0, n - 1);

		System.out.println("sorted array"+ printArray(arr));
	}
}