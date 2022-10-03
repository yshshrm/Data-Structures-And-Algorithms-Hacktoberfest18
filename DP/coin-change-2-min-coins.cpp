// very similar to unbound knapsack

class Solution
{
public:
    int minCoins(int coins[], int m, int v)
    {
        int t[m + 1][v + 1], i, j;
        int inf = INT_MAX - 1;

        // init
        memset(t, 0, sizeof(t));
        for (i = 0; i < v + 1; i++)
            t[0][i] = inf;

        // main
        for (i = 1; i <= m; i++)
            for (j = 1; j <= v; j++)
                if (coins[i - 1] > j)
                    t[i][j] = t[i - 1][j];
                else
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
        // cuz of the above line, we subtract 1 from INT_MAX

        if (t[m][v] == inf)
            return -1;

        return t[m][v];
    }
};