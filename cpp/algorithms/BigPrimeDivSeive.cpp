//Biggest Prime Divisor Sieve O(n log log n)
#include <bits/stdc++.h>
using namespace std;

int main () {
    //precal( (int)1e7 );
    int n;
    cin>>n;
    
    int big[n + 1] = {1, 1};
    for (int i = 1; i <= n; ++i)
     if (big[i] == 1)
      for (int j = i; j <= n; j += i)
       big[j] = i; 

    for(int i=1;i<=n;i++){
        cout<<big[i]<<" ";
    }
return 0;    
}
