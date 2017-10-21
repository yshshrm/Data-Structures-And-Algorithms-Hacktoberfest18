
/**
 * Created by antrix190 on 22/10/2017
 */
public class HeapSort {
	/*
	 * HeapSort is a comparison based sorting algorithms that uses a binary heap data structure. Its run time 
	 * complexity is O(nlogn).
	 * */
	public void sort(int arr[]){

		int n = arr.length;

		//Create heap
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		for (int i=n-1; i>=0; i--){
			//Moving current root to the end.
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			//call Max heapify on the remaining heap.
			heapify(arr, i, 0);
		}
	}

	void heapify(int arr[], int n, int i){
		//init 
		int largest = i;  
		int l = 2*i + 1;  
		int r = 2*i + 2;  

		//if left child is larger than root, largest =left.
		if (l < n && arr[l] > arr[largest])
			largest = l;
		//if right child is larger than largest, largest =right
		if (r < n && arr[r] > arr[largest])
			largest = r;

		//if largest is not root.
		if (largest != i){
			
			//rearrange the heap.
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			//Recursively heapify.
			heapify(arr, n, largest);
		}
	}
}
