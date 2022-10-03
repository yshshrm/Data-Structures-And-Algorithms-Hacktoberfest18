int LCS(char X[], char Y[], int m, int n)
{
    int i, j, t[m + 1][n + 1];
    memset(t, 0, sizeof(t));

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (X[i - 1] == Y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);

    return t[m][n];
}

int shortestCommonSupersequence(char *X, char *Y, int m, int n)
{
    return m + n - LCS(X, Y, m, n);
}