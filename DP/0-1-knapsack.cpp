#include <algorithm>
using namespace std;

// Method 1 - Simple Recursion [RESULTS IN TLE]
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

// Method 2 - Recursion With Memoization [OPTIMIZED -> NO TLE]
int _knapSack(int W, int wt[], int val[], int n, int t[1001][1001])
{
    if (n == 0 || W == 0)
        return 0;

    if (t[n][W] != -1)
        return t[n][W];

    if (wt[n - 1] > W)
        return t[n][W] = _knapSack(W, wt, val, n - 1, t);
    else
        return t[n][W] = max(val[n - 1] + _knapSack(W - wt[n - 1], wt, val, n - 1, t), _knapSack(W, wt, val, n - 1, t));
}

int knapSack(int W, int wt[], int val[], int n)
{
    int t[1001][1001];
    memset(t, -1, sizeof(t));
    return _knapSack(W, wt, val, n, t);
}

// Method 3 - Bottom-Up Approach [FASTEST]
int knapSack(int W, int wt[], int val[], int n)
{
    // initialization
    int i, j, t[1001][1001];
    for (i = 0; i < n + 1; i++)
        for (j = 0; j < W + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (i = 1; i < n + 1; i++)
        for (j = 1; j < W + 1; j++)
            if (wt[i - 1] > j)
                t[i][j] = t[i - 1][j];
            else
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);

    return t[n][W];
}
