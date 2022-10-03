// Extremely Similar to printing LCS

class Solution
{
public:
    string shortestCommonSupersequence(string A, string B)
    {
        int m = A.size(), n = B.size();
        int i, j, t[m + 1][n + 1];
        string s;

        // initialize dp matrix
        memset(t, 0, sizeof(t));

        // generate table
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                if (A[i - 1] == B[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);

        // reverse engineer
        i = m, j = n;
        while (i > 0 && j > 0)
            if (A[i - 1] == B[j - 1])
            {
                s.push_back(A[i - 1]);
                i--;
                j--;
            }
            else if (t[i][j - 1] > t[i - 1][j])
            {
                s.push_back(B[j - 1]);
                j--;
            }
            else
            {
                s.push_back(A[i - 1]);
                i--;
            }

        while (i > 0)
        {
            s.push_back(A[i - 1]);
            i--;
        }

        while (j > 0)
        {
            s.push_back(B[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};