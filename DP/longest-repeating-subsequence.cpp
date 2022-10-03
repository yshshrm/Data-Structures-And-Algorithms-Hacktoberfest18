class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        int i, j, n = str.size();
        int t[n + 1][n + 1];
        memset(t, 0, sizeof(t));

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (str[i - 1] == str[j - 1] && i != j)
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);

        return t[n][n];
    }
};