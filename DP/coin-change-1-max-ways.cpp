// very similar to count subsets of given sum but with unbound knapsack pattern
class Solution
{
public:
    long long int count(int S[], int m, int n)
    {
        long long t[m + 1][n + 1], i, j;
        memset(t, 0, sizeof(t));
        for (i = 0; i <= m; i++)
            t[i][0] = 1;

        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                if (S[i - 1] > j)
                    t[i][j] = t[i - 1][j];
                else
                    t[i][j] = t[i][j - S[i - 1]] + t[i - 1][j];

        return t[m][n];
    }
};