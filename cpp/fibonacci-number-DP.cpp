#include <iostream>
#include <vector>
using namespace std;

//program to calculate nth fibonacci number
long long fib(int n, vector<long long> &dp)
{
    if(n == 1 || n == 2)
        return 1;

    // Checking if Nth term is already computed or not
    if(dp[n] != 0) 
        return dp[n];

    // Storing the computed values
    return dp[n] = fib(n-1, dp)+fib(n-2, dp); 
}

int main()
{
    int n;
    cin >> n;
    vector<long long> dp(101); // Creating the array for storing computed values
    cout << fib(n, dp);
}
