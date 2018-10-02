/**
 * Created by renu.yadav on 20/10/17.
 */
public class selection_sort {
    /**
     * selection sort in iteration , picks up the ith min element and keep it in place
     * so after every ith iteration ith minimum element is in place
     * takes O(n^2)
     * @param arr
     * @return
     */
    public static int[] selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int minIndex = i;
            int minElement = arr[minIndex];
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < minElement) {
                    minIndex = j;
                }
            }
            // swap , arr[i] with minElement
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return arr;
    }

}
