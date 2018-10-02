import java.util.Arrays;
import java.util.Scanner;

public class Sieve_of_Eratosthenes {

	//Algorithm given below
	
	// The sieve of Eratosthenes is one of the most efficient ways
	// to find all primes smaller than n when n is smaller than 10 million or so.

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);

		// Input the given number
		int n = scn.nextInt();
		System.out.println("The prime numbers upto " + n + "are : -");
		sieve_of_eratosthenes(n);

	}

	public static void sieve_of_eratosthenes(int n) {

		// Take a boolean array of size n+1

		boolean primes[] = new boolean[n + 1];

		// Fill all the indices with true value initially
		Arrays.fill(primes, true);

		// In the array primes[] the value 2 and 3 are prime so mark there places as
		// false
		primes[0] = false;
		primes[1] = false;

		for (int table = 2; table * table <= n; table++) {
			if (primes[table] == false)
				continue;

			for (int multiplier = 2; multiplier * table <= n; multiplier++) {

				// If the number is not prime set it's index to false
				primes[table * multiplier] = false;
			}
		}
		for (int i = 2; i <= n; i++) {
			if (primes[i] == true)
				System.out.println(i);
		}
	}

	
	
	// Algorithm :-
	// 1. Create a list of consecutive integers from 2 to n.
	
	// 2. Initially, let p equal 2, the first prime number.
	
	// 3.Starting from p, count up in increments of p and mark each of these numbers
	// greater than p itself in the list.
	// These numbers will be 2p, 3p, 4p, etc.;
	// note that some of them may have already been marked.
	
	// 4 .Find the first number greater than p in the list that is not marked.
	// If there was no such number, stop. Otherwise, let p now equal this number
	// (which is the next prime),
	// and repeat from step 3.

}
