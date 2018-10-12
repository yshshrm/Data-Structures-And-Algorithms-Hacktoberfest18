public class quicksort {

	private static int[] l;
	
	public static void Sort(int[] a) {
		l = a;
		int len = l.length;
		Quicksort(0,len-1);
		for (int p = 0; p < len; p++) {
			System.out.println(l[p]);
		}
	}
	
	public static void Quicksort(int low, int high) {
		
		
		int pivot = l[low];
		
		int i = low + 1;
		int j = high;
		
		while (i<=j) {
			while (i <= high && l[i] < pivot) {
				i++;
			}
			
			while (j > low && l[j] > pivot) {
				j--;
			}
			
			if (i<j) {
				int temp = l[i];
				l[i] = l[j];
				l[j] = temp;
				i++;
				j--;
			}
			
		}
		
		int temp = l[low];
		l[low] = l[j];
		l[j] = temp;
		
		if (low < j-1) {
			Quicksort(low,j-1);
		}
		
		if (j+1 < high) {
			Quicksort(j+1,high);
		}
	}
	
	
	public static void main(String[] args) {
		
		int[] a = {1,4,67,2,78,3,56,7,2,45,7,4,2,45};
		Sort(a);
	}

}
