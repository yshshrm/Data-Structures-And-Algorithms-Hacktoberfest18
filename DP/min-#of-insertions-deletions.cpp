// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2.

class Solution
{
    int LCS(string A, string B, int m, int n)
    {
        int i, j, t[m + 1][n + 1];
        memset(t, 0, sizeof(t));

        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                if (A[i - 1] == B[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);

        return t[m][n];
    }

public:
    int minOperations(string str1, string str2)
    {
        int m = str1.size(), n = str2.size();
        return m + n - 2 * LCS(str1, str2, m, n);
    }
};