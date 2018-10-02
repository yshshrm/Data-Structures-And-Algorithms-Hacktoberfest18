import java.util.Scanner;
public class knapsack {

    static int optimalWeight(int W, int[] w) {
        int n = w.length;
        int[][] table = new int[n + 1][W + 1];
        for (int j = 0; j <= W; j++) table[0][j] = 0;
        for (int i = 0; i <= n; i++) table[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int weight = 1; weight <= W; weight++) {
                table[i][weight] = table[i - 1][weight];
                if (weight < w[i - 1]) continue;
                table[i][weight] = Math.max(
                        table[i][weight],
                        table[i - 1][weight - w[i - 1]] + w[i - 1]);
            }
        }
        return table[n][W];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int W, n;
        W = scanner.nextInt();
        n = scanner.nextInt();
        int[] w = new int[n], v = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
        System.out.println(optimalWeight(W, w));
    }
}
