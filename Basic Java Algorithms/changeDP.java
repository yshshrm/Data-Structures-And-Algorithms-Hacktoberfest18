import java.util.*;

public class changeDP {
    static int optimalWeight(int W, int[] w) {
        int num_items = 0;
        for (int item : w) {
            if (item <= W)
                num_items++;
        }
        int[] items = new int[num_items];
        int index = 0;
        for (int i = 0; i < w.length - 1; i++) {
            if (w[i] <= W) {
                items[index] = w[i];
                index++;
            }
        }

        int capacity = W + 1;

        int K[][] = new int[items.length + 1][capacity];

        for (int col = 0; col <= W; col++) {
            K[0][col] = 0;
        }

        for (int row = 0; row <= items.length; row++) {
            K[row][0] = 0;
        }

        for (int item = 1; item <= items.length; item++) {
            for (int weight = 1; weight <= W; weight++) {
                if (items[item - 1] <= weight) {
                    K[item][weight] = Math.max(items[item - 1] + K[item - 1][weight - items[item - 1]],
                            K[item - 1][weight]);
                } else {
                    K[item][weight] = K[item - 1][weight];
                }
            }
        }
        return K[items.length + 1][capacity];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int W, n;
        W = scanner.nextInt();
        n = scanner.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
        System.out.println(optimalWeight(W, w));
    }
}
