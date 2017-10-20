/**
 * Created by renu.yadav on 20/10/17.
 */
public class insertion_sort {
    /**
     * insertion sort picks up the current element(i) and checks it against its previous element(j = i-1 until j>=0) and place it
     * takes O(n^2) and inplace algo with no extra space
     * @param arr
     * @return
     */

    public static int[] insertionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int keyToBeInserted = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > keyToBeInserted) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = keyToBeInserted;
        }
        return arr;
    }
}
