#include <iostream>
#include <cstring>
using namespace std;

int countSubsets(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1], i, j;
    memset(t, 0, sizeof(t));
    for (i = 0; i <= n; i++)
        t[i][0] = 1;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= sum; j++)
            if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
            else
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];

    return t[n][sum];
}

int main()
{
    int arr[] = {1, 1, 2, 3}, n = 4;
    int diff = 1, range = 0, toFind;
    for (int i = 0; i < n; i++)
        range += arr[i];
    toFind = (range - diff) / 2;
    cout << countSubsets(arr, n, toFind);
}