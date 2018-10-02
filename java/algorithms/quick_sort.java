import java.util.*;

public class quick_sort {
	public static void main(String[] args) {
		int[] a = { 9, 2, 4, 7, 3, 7, 10 };
		quickSort(a, 0, a.length - 1);
		System.out.println(Arrays.toString(a));
	}
 
	public static void quickSort(int[] arr, int lo, int hi) {
		if (arr == null || arr.length == 0)
			return;
 
		if (lo >= hi)
			return;
 
		// pick the pivot
		int middle = lo + (hi - lo) / 2;
		int pivot = arr[middle];
 
		// make left < pivot and right > pivot
		int i = lo, j = hi;
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
 
			while (arr[j] > pivot) {
				j--;
			}
 
			if (i <= j) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
		}
 
		// recursively sort two sub parts
		if (lo < j)
			quickSort(arr, lo, j);
 
		if (hi > i)
			quickSort(arr, i, hi);
	}
}