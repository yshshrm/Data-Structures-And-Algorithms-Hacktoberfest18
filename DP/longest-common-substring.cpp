// extremely similar to LCS

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int i, j, t[n + 1][m + 1], maxLength = 0;
        memset(t, 0, sizeof(t));

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if (S1[i - 1] == S2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    maxLength = max(maxLength, t[i][j]);
                }
                else
                    t[i][j] = 0;

        return maxLength;
    }
};