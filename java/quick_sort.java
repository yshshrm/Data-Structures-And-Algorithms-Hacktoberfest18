public class quick_sort {
    /**
     * quick sort works on divide and conquer technique , by chossing a pivot element
     * below code chooses last arr[n-1] element as pivot element and recursively placing all elements < pivot element on left
     * and all elements >pivot on right side of pivot , and thus placing pivot in correct place
     * Complexity: takes O(n^2) in worst case (array is already sorted ) ,and O(nlgn) in avg and best case
     * Space complexity ; No extra space required
     * @param arr
     * @param low
     * @param high
     */

    public static void quickSort(int[] arr, int low, int high) {
        if (low >= high)
            return;
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);

    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        int j = low;
        while (j < high) {
            if (arr[j] <= pivot) {
                i++;
                // swap elements
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        // swap arr[i+1] with arr[high]
        int temp = arr[high];
        arr[high] = arr[i + 1];
        arr[i + 1] = temp;
        return i + 1;
    }
}