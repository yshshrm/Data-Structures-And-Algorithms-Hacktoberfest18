#include <algorithm>
using namespace std;

// Bottom-Up Approach [FASTEST]
class Solution
{
public:
    unsigned long long perfectSum(int arr[], int n, int sum)
    {
        unsigned long long t[n + 1][sum + 1], i, j;
        memset(t, 0, sizeof(t));
        for (i = 0; i < n + 1; i++)
            t[i][0] = 1;

        for (i = 1; i < n + 1; i++)
            for (j = 1; j < sum + 1; j++)
                if (arr[i - 1] <= j)
                    t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % 1000000007;
                else
                    t[i][j] = t[i - 1][j];

        return t[n][sum];
    }
};