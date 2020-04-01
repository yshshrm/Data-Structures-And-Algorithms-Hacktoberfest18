import java.util.Arrays;
import java.util.Scanner;

public class Sieve_of_Eratosthenes
{
	// Algorithm given below
	
	// The sieve of Eratosthenes is one of the most efficient ways
	// to find all primes smaller than n when n is smaller than ~10 million

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		// Input the given number
		int n = input.nextInt();
		System.out.println("The prime numbers up to " + n + " are:");
		sieve_of_eratosthenes(n);
	}

	public static void sieve_of_eratosthenes(int n)
	{
		// Take a boolean array of size n+1
		boolean primes[] = new boolean[n + 1];

		// Fill all the indices with true value initially
		Arrays.fill(primes, true);

		// In the array primes[] the values 0 and 1 are non-prime so mark them as false
		primes[0] = false;
		primes[1] = false;

		for (int p = 2; p * p <= n; p += (p == 2 ? 1 : 2))
		{
			if (!primes[p])
			{
				continue;
			}

			for (int multiplier = p; multiplier * p <= n; multiplier++)
			{
				// The number is not prime, so set its index to false
				primes[p * multiplier] = false;
			}
		}
		for (int i = 2; i <= n; i++)
		{
			if (primes[i])
			{
				System.out.println(i);
			}
		}
	}

	
	
	// Algorithm:
	// 1. Create an array of consecutive integers from 2 to n.
	
	// 2. Initially, let p equal 2, the first prime number.
	
	// 3. Eliminate all multiples of 2 since none of them are prime numbers and then set p equal to 3.
	
	// 4. Starting from p, count up in increments of 2 and for each multiplier
	// greater than p, mark its multiple as non-prime in the list.
	// These numbers will be p * p, p * (p+1), p * (p+2), etc.;
	// note that some of them may have already been marked.
	
	// 5. Find the first number greater than p in the list that is not marked.
	// If there was no such number, stop. Otherwise, let p now equal this number
	// (which is the next prime),
	// and repeat from step 3.

}
