import java.util.*;

public class primitive_calculator {
    private static List<Integer> optimal_sequence(int n) {
        List<Integer> sequence = new ArrayList<Integer>();
        while (n >= 1) {
            sequence.add(n);
            if (n % 3 == 0) {
                n /= 3;
            } else if (n % 2 == 0) {
                n /= 2;
            } else {
                n -= 1;
            }
        }
        Collections.reverse(sequence);
        return sequence;
    }

    private static List<Integer> dynamic_sequence(int n) {
        int[] a = new int[n + 1];
        int[] predecessor = new int[n + 1];

        for (int i = 2; i <= n; i++) {
            a[i] = a[i - 1] + 1;
            predecessor[i] = i - 1;
            if (i % 3 == 0) {
                if (a[i / 3] < a[i]) {
                    a[i] = a[i / 3] + 1;
                    predecessor[i] = i / 3;
                }
            }
            if (i % 2 == 0) {
                if (a[i / 2] < a[i]) {
                    a[i] = a[i / 2] + 1;
                    predecessor[i] = i / 2;
                }
            }
        }

        ArrayList<Integer> sequence = new ArrayList<Integer>();

        for (int i = n; i != 0; i = predecessor[i]) {
            sequence.add(i);
        }

        Collections.reverse(sequence);
        return sequence;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> sequence = dynamic_sequence(n);
        System.out.println(sequence.size() - 1);
        for (Integer x : sequence) {
            System.out.print(x + " ");
        }
    }
}
