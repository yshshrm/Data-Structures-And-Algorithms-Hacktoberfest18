// GFG [HARD] -> FASTEST SOLUTION -> execution time : [0.02]

class Solution
{
public:
    int subsetSum(int arr[], int n, int sum)
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
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];

        for (i = sum; i >= 0; i--)
            if (t[n][i] == 1)
                break;

        return i;
    }

    int minDiffernce(int arr[], int n)
    {
        int i, range = 0;
        for (i = 0; i < n; i++)
            range += arr[i];
        return range - (2 * subsetSum(arr, n, range / 2));
    }
};