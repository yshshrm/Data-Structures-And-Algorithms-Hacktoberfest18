import java.lang.Math;
import java.util.ArrayList;

public class PrimeFactorization {
  public static ArrayList<Integer> findPrimeFactors(int num) {

    ArrayList<Integer> primeFactors = new ArrayList();

    // add the number of 2s that divide n
    while(num % 2 == 0) {
      primeFactors.add(2);
      num = num / 2;
    }

    // at this point number is odd
    for (int i=3; i<=Math.sqrt(num); i++) {
      while (num % i == 0) {
        primeFactors.add(i);
        num = num / i;
      }
    }

    // at this point n is a prime number
    // has to be greater than 2
    if(num > 2) {
      primeFactors.add(num);
    }

    return primeFactors;

  }

  public static void main(String[] args) {
    int num = 25;
    System.out.println(findPrimeFactors(num));
  }
}
