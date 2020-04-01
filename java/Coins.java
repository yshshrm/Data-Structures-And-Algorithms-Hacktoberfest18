import java.util.HashMap;

public class Coins {

    public static void main(String[] args) {
        int[] arr = {1, 5, 10, 25};
        System.out.println(numberOfWays(56, arr, new HashMap<>()));
    }


    private static int numberOfWays(int n, int[] coins, HashMap<Integer, Integer> dp) {
        if (n < 0) {
            return 0;
        } else if (n == 0) {
            return 1;
        }

        int count = 0;
        if (dp.containsKey(n)) {
            count += dp.get(n);
        } else {
            for (int i = 0; i < coins.length; i++) {
                count += numberOfWays(n - coins[i], coins, dp);
            }
        }

        dp.put(n, count);
        return count;
    }
}
