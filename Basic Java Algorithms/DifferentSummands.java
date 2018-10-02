import java.util.*;

public class DifferentSummands {
    private static List<Integer> optimalSummands(int n) {
        List<Integer> summands = new ArrayList<Integer>();
         for (int i = 1; i <= n; i++) {
            n -= i;
            if (n <= i) {
                summands.add(n + i);
            } else if (n == 0) {
                summands.add(i);
                break;
            } else {
                summands.add(i);
            }
        }
        return summands;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> summands = optimalSummands(n);
        System.out.println(summands.size());
        for (Integer summand : summands) {
            System.out.print(summand + " ");
        }
    }
}

