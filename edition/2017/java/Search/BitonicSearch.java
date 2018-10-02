public class BitonicSearch {

	public static void main(String[] args) {
		int[] a = { 1, 2, 5, 9, 50, 522, 15, 2 };

		// first find the Bitonic Max in array
		int maxIndex = bitonicMax(a, 0, a.length - 1);

		// find in both left and right of this index to find the element
		System.out.println(leftBinarySearch(a, 0, maxIndex, 2));
		System.out.println(rightBinarySearch(a, maxIndex, a.length - 1, 2));

	}

	public static int leftBinarySearch(int arr[], int low, int hi, int query) {
		if (hi >= low) {
			int mid = low + (hi - low) / 2;
			if (query == arr[mid]) {
				return mid;
			} else if (query < arr[mid]) {
				return leftBinarySearch(arr, low, mid - 1, query);
			} else if (query > arr[mid]) {
				return leftBinarySearch(arr, mid + 1, hi, query);
			}
		}
		return -1;
	}

	public static int rightBinarySearch(int arr[], int low, int hi, int query) {
		if (hi >= low) {
			int mid = low + (hi - low) / 2;
			if (query == arr[mid]) {
				return mid;
			} else if (query > arr[mid]) {
				return rightBinarySearch(arr, low, mid - 1, query);
			} else if (query < arr[mid]) {
				return rightBinarySearch(arr, mid + 1, hi, query);
			}
		}
		return -1;
	}

	public static int bitonicMax(int arr[], int low, int high) {
		if (low == high) {
			return low;
		}
		int mid = low + (high - low) / 2;
		if (arr[mid] < arr[mid + 1]) {
			return bitonicMax(arr, mid + 1, high);
		}
		if (arr[mid] > arr[mid + 1]) {
			return bitonicMax(arr, low, mid);
		}
		return mid;
	}
}
