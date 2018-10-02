/**
 * Created by Beven Lee on 23/10/17.
 */
public class RecursiveBinarySearch {

    public static int recursiveBinarySearch(int[] sortedArray, int start, int end, int key) {

        if (start < end) {
            int mid = start + (end - start) / 2;
            if (key < sortedArray[mid]) {
                return recursiveBinarySearch(sortedArray, start, mid, key);

            } else if (key > sortedArray[mid]) {
                return recursiveBinarySearch(sortedArray, mid + 1, end, key);

            } else {
                return mid;
            }
        }
        return -(start + 1);
    }

    public static void main(String[] args) {

        int[] arr1 = {2, 45, 234, 567, 876, 900, 976, 999};
        int index = recursiveBinarySearch(arr1, 0, arr1.length, 45);
        System.out.println("Found 45 at " + index + " index");
        index = recursiveBinarySearch(arr1, 0, arr1.length, 999);
        System.out.println("Found 999 at " + index + " index");
        index = recursiveBinarySearch(arr1, 0, arr1.length, 876);
        System.out.println("Found 876 at " + index + " index");
    }
}
