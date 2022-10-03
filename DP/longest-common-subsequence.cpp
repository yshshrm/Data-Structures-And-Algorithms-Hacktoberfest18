#include <algorithm>
#include <string>
using namespace std;

// Method 1 - Simple Recursion [RESULTS IN TLE]
int lcs(int x, int y, string s1, string s2)
{
    if (x == 0 || y == 0)
        return 0;

    if (s1[x - 1] == s2[y - 1])
        return 1 + lcs(x - 1, y - 1, s1, s2);
    else
        return max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
}

// Method 2 - Recursion With Memoization [OPTIMIZED -> NO TLE]
int t[101][101];

int _lcs(int x, int y, string s1, string s2)
{
    if (x == 0 || y == 0)
        return 0;

    if (t[x][y] != -1)
        return t[x][y];

    if (s1[x - 1] == s2[y - 1])
        return t[x][y] = 1 + _lcs(x - 1, y - 1, s1, s2);
    else
        return t[x][y] = max(_lcs(x - 1, y, s1, s2), _lcs(x, y - 1, s1, s2));
}

int lcs(int x, int y, string s1, string s2)
{
    memset(t, -1, sizeof(t));
    return _lcs(x, y, s1, s2);
}

// Method 3 - Bottom-Up Approach [FASTEST]
int lcs(int x, int y, string s1, string s2)
{
    int t[x + 1][y + 1], i, j;
    memset(t, 0, sizeof(t));

    for (i = 1; i <= x; i++)
        for (j = 1; j <= y; j++)
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);

    return t[x][y];
}