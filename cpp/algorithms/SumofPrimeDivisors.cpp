// Sum of all (including primes and non primes) Divisors Sieve O(n log n)
#include<iostream>
using namespace std;

int main () {
    
    int n;
    cin>>n;
    
    int sumdiv[n + 1]{0};
    for (int i = 1; i <= n; ++i)
     for (int j = i; j <= n; j += i)
      sumdiv[j] += i;
    
    //Prints all divisors sum from 1 to N
    for(int i=1;i<=n;i++){
        cout<<sumdiv[i]<<" ";
    }
   
    //Sum of all prime Divisors of a number O(nlogn)
    int primediv[n+1]{0};
    for(int i=2;i<=n;i++){
        if(primediv[i] == 0){
            for(int j=i; j<=n; j+=i){
                 primediv[j] += i;
            }
        }
    }
    //Print all divisors sum of primes till 1 to N
    for(int i=0; i<n; i++){
        cout<<primediv[i]<<" ";
  }
return 0;
}
