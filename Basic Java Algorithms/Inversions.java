import java.util.*;

public class Inversions {
    private static long merge(int[] a, int[] b, int left, int ave, int right) {
        int i = left, j = ave, k = left;
        long inv_count = 0;
        while (i <= ave - 1 && j <= right) {
            if (a[i] <= a[j]) {
                b[k] = a[i];
                i++;
            } else {
                b[k] = a[j];
                inv_count += ave - i;
                j++;
            }
            k++;
        }
        while (i <= ave - 1) {
            b[k] = a[i];
            i++;
            k++;
        }
        while (j <= right) {
            b[k] = a[j];
            j++;
            k++;
        }
        for (i = left; i <= right; i++) {
            a[i] = b[i];
        }
        return inv_count;
    }

    private static long getNumberOfInversions(int[] a, int[] b, int left, int right) {
        long inv_count = 0;
        if (right <= left) {
            return inv_count;
        }
        int ave = left + (right - left) / 2;
        inv_count += getNumberOfInversions(a, b, left, ave);
        inv_count += getNumberOfInversions(a, b, ave + 1, right);
        inv_count += merge(a, b, left, ave + 1, right);
        return inv_count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] b = new int[n];
        System.out.println(getNumberOfInversions(a, b, 0, a.length - 1));
    }
}
