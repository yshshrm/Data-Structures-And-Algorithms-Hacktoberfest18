/**
 * Created by renu.yadav on 20/10/17.
 */
public class bubble_sort {
    /**
     * bubble sort , compares adjacent values and swap them if needed,
     * after every  ith iteration ,ith biggest element would be in place
     * takes O(n^2) and an inplace algorithm with no extra space.
     * @param arr
     * @return
     */
    //
    public int[] bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j + 1] < arr[j]) {
                    // swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr;
    }
}
