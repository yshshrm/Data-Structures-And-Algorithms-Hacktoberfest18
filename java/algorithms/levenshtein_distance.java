import java.lang.Math;
import java.lang.System;

class levenshtein_distance {
    static int calculate_distance(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        int[][] dp = new int[m+1][n+1];

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = Math.max(i, j);
                else {
                    int cost = 0;
                    if (s1.charAt(i-1) != s2.charAt(j-1))
                        cost = 1;
                    dp[i][j] = Math.min(Math.min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + cost);
                }
            }
        }

        return dp[m][n];
    }
    public static void main(String[] args) {
        String s1 = "kitten";
        String s2 = "sitting";

        System.out.println(calculate_distance(s1, s2));
    }
}