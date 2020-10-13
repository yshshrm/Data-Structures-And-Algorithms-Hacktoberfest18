#include<stdio.h>

//Added a typedef enum with object bool to implement bool,
// since it isn't present in C.

typedef enum 
{
    false, true
}bool;



void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    for(int i = 0;i<n+1;i++)
    {        
        prime[i]=true;
    }
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Eliminate all multiples of p greater than or  
            // equal to the square of it since 
            // numbers which are multiple of p and are 
            // less than its square are assigned true initially and are primes
            // since they do not have common factors with previous numbers  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]!=false) 
            printf("%d ", p); 
} 
  


// Driver Program to test above function 
int main() 
{ 
    int n;

    printf("\n\n\tEnter the number to find the prime numbers preceding it: ");
    scanf("%d",&n); 
    
    printf("\n\n\tThe following are the prime numbers smaller than or equal to %d:\n\n\t", n);
    SieveOfEratosthenes(n); 
    
    printf("\n");

    return 0; 
} 