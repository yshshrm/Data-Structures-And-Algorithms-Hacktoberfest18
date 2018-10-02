import java.util.Arrays;

public class PrimeNumber {
    
    // Sieve_of_Eratosthenes Method 
    private static boolean[] primes = null; // Initialization of an array containing whether number is prime or not

    /** 
     * @see <a href="https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes">Sieve of Eratosthenes (Wikipedia)</a>
     */
    public static final boolean isPrime(int number) {
        if (number == 1) {
            return false;
        }
        if (primes == null || number >= primes.length) {
            int start = 2;

            if (primes == null) {
            	primes = new boolean[number + 1];  // Creating a new Array upto N numbers
            } else if (number >= primes.length) {
            	primes = Arrays.copyOf(primes, number + 1);
            }
            /**
             * Finding the values of the prime boolean array
             */
            for (int i = start; i <= Math.sqrt(number); i++) {
                if (!primes[i]) {
                    for (int j = i * 2; j <= number; j += i) {
                    	primes[j] = true;
                    }
                }
            }
        }
        return !primes[number];
    }
}
