//Euler Totient Sieve O(n log log n)

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;
    
    int totient[n + 1];
    for (int i = 1; i <= n; ++i) totient[i] = i;
    for (int i = 2; i <= n; ++i)
     if (totient[i] == i)
      for (int j = i; j <= n; j += i)
       totient[j] -= totient[j] / i;
    
    // To print the totient array
    for(int i=0;i<n;i++){
    cout<<totient[i]<<" ";
    }
    
return 0;
}
