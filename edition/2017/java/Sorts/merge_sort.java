
/**
 * Created by renu.yadav on 20/10/17.
 */
public class merge_sort {
    /**
     * Merge sort also works on divide and conquer , by dividing array in halves and then merging them back in order
     * Complexity: O(nlgn) in average , best and worst case
     * SpaceComplexity:  because of merging in order , we need extra space O(n) (its not an in place algorithm)
     *
     * @param arr
     * @param low
     * @param high
     */
    public static void mergeSort(int[] arr, int low, int high) {
        if (low >= high)
            return;
        int medium = low + (high - low) / 2;
        mergeSort(arr, low, medium);
        mergeSort(arr, medium + 1, high);
        merge(arr, low, medium, high);
    }

    public static void merge(int[] arr, int low, int medium, int high) {
        int s1 = medium - low + 1;// two sizes
        int s2 = high - medium;
        int[] a1 = new int[s1];
        int[] a2 = new int[s2];
        for (int i = 0; i < s1; i++) {
            a1[i] = arr[low + i];
        }
        for (int i = 0; i < s2; i++) {
            a2[i] = arr[medium + i + 1];
        }
        // now merge them in original array
        int i = 0;
        int j = 0;
        int k = low;
        // keep on merging them back in original , with correct order
        while (i < s1 && j < s2) {
            if (a1[i] <= a2[j]) {
                arr[k] = a1[i];
                i++;
            } else {
                arr[k] = a2[j];
                j++;
            }
            k++;
        }
        // place all remaining elements of s1
        while (i < s1) {
            arr[k] = a1[i];
            i++;
            k++;

        }
        // place all remaining elements of s2
        while (j < s2) {
            arr[k] = a2[j];
            j++;
            k++;
        }
    }
}
