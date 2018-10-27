// Programme to calculate prime numbers from 1 to N in O(logn) time.
#include<iostream>
using namespace std;

int main () {
    
    int n;
    cin>>n;
    
    //Divisor Sieve O(n log n)
    int divisors[n + 1]{0};
    for (int i = 1; i <= n; ++i)
     for (int j = i; j <= n; j += i)
      ++divisors[j];

    //Prints No of divisors from 1 to N
    for(int i=1;i<=n;i++){
        cout<<divisors[i]<<" ";
    }

return 0;
}
