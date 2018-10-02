import java.util.HashMap;
import java.util.Map;

public class FibonnaciDP {
	static Map<Integer, Long> fib = new HashMap<>();

	public static long fibonnaciTopDown(int arg) {
		if (arg == 0 || arg == 1) {
			fib.put(arg, (long) arg);
		}
		if (!fib.containsKey(arg)) {
			fib.put(arg, fibonnaciTopDown(arg - 1) + fibonnaciTopDown(arg - 2));
		}
		return fib.get(arg);
	}

	public static long fibonnaciBottomUp(int arg) {
		int dp[] = new int[arg + 1];
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= arg; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[arg];
	}
}