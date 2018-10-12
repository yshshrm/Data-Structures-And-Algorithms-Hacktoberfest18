 
#include<bits/stdc++.h> 
using namespace std; 
  

int nCrModpDP(int n, int r, int p) 
{ 
    
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
  

int nCrModpLucas(int n, int r, int p) 
{ 
  
   if (r==0) 
      return 1; 
  
  
   int ni = n%p, ri = r%p; 
  
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 
  

int main() 
{ 
    int n = 1000, r = 900, p = 13; 
    cout << "Value of nCr % p is " << nCrModpLucas(n, r, p); 
    return 0; 
} 
