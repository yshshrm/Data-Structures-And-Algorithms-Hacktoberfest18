#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int LCS(string A, string B, int m, int n)
{
    int i, j, t[m + 1][n + 1];
    memset(t, 0, sizeof(t));

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (A[i - 1] == B[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);

    return t[m][n];
}

int LPS(string A)
{
    int n = A.size();
    string B = A;
    reverse(B.begin(), B.end());
    return LCS(A, B, n, n);
}

int minDeletions(string A)
{
    int n = A.size();
    return n - LPS(A);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        cout << minDeletions(S) << "\n";
    }
    return 0;
}