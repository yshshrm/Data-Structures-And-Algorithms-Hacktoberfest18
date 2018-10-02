import java.util.Arrays;
import java.util.Random;

public class InsertionSort {

	public static <E extends Comparable<? super E>> void sort(E[] array) {
		if (array == null || array.length < 2) { return; }
		
		for (int i = 1; i < array.length; i++) {
			int j = i;
			E val = array[j];
			while (j > 0 && val.compareTo(array[j - 1]) < 0) {
				array[j] = array[j - 1];
				j = j - 1;
			}
			if (j != i) {
				array[j] = val;
			}
		}
	}
	
	public static void main(String[] args) {
		final int LEN = 15;
		final int MAX_RANDOM = 100;
		final Integer[] ar = new Integer[LEN];
		Random rnd = new Random();
		for (int i = 0; i < LEN; i++) {
			ar[i] = new Integer(rnd.nextInt(MAX_RANDOM));
		}
		System.out.println(Arrays.toString(ar));
		
		sort(ar);
		System.out.println(Arrays.toString(ar));
	}

}
