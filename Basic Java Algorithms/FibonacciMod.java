import java.util.*;

public class FibonacciMod {
    private static long getFibonacciHugeNaive(long n, long m) {
        if (n <= 1)
            return n;

        long previous = 0;
        long current = 1;

        for (long i = 0; i < n - 1; ++i) {
            long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
        }

        return current % m;
    }

    private static long pisanoPeriodLength(long m) {
        long F1 = 0, F2 = 1, F = F1 + F2, length = 0;
        for (int i = 0; i < m * m; i++) {
            F = (F1 + F2) % m;
            F1 = F2;
            F2 = F;
            if (F1 == 0 && F2 == 1) {
                length = i + 1;
                break;
            }
        }
        return length;
    }

    private static long getFibonacciHugeFast(long n, long m) {
        long remainder = n % pisanoPeriodLength(m);

        long F1 = 0, F2 = 1, F = remainder;
        for (int i = 1; i < remainder; i++) {
            F = (F1 + F2) % m;
            F1 = F2;
            F2 = F;
        }
        return F % m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        System.out.println(getFibonacciHugeFast(n, m));
    }
}
