// Iterative solution for Josephus Problem  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function for finding the winning child. 
long long int find(long long int n, long long int k) 
{ 
    long long int sum = 0, i; 
  
    // For finding out the removed  
    // chairs in each iteration 
    for (i = 2; i <= n; i++) 
        sum = (sum + k) % i; 
  
    return sum + 1; 
} 
  
// Driver function to find the winning child 
int main() 
{ 
    int n = 14, k = 2; 
    cout << find(n, k); 
    return 0; 
} 
Output:
13
