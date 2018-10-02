import java.util.*;

public class FibonacciPartialSum {
    private static long getFibonacciPartialSumNaive(long from, long to) {
      if(to <= 1)
	      return to;
        long p = 0;
        long c  = 1;
        for (long i = 0; i < from-1; ++i) {
            long temp = p;
            p = c;
            c=temp+c;
        }
	long sum=c;
	for(long i=0;i<to-from;++i){
		long temp=p;
		p=c;
		c=temp+c;
		sum+=c;
	}
        return sum % 10;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long from = scanner.nextLong();
        long to = scanner.nextLong();
        System.out.println(getFibonacciPartialSumNaive(from, to));
    }
}

