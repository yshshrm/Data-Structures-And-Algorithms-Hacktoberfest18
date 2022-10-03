#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// time : o(n2) solution | gap strategy + suffix strategy
// IMPORTANT
// Watch Video: https://www.youtube.com/watch?v=qmTtAbOTqcg
class Solution
{
public:
    int palindromicPartition(string str)
    {
        int length = str.size(), i, j, g;
        // Make Palindrome Table | GAP STRATEGY
        vector<vector<bool>> t(length, vector<bool>(length));
        for (int g = 0; g < length; g++)
            for (int i = 0, j = g; j < length; i++, j++)
                if (g == 0)
                    t[i][j] = true;
                else if (g == 1)
                    t[i][j] = str[i] == str[j];
                else if (str[i] == str[j] && t[i + 1][j - 1] == true)
                    t[i][j] = true;
                else
                    t[i][j] = false;

        // Make ans array | SUFFIX STRATEGY
        vector<int> ans(length);
        ans[0] = 0;

        for (j = 1; j < length; j++)
        {
            if (t[0][j])
                ans[j] = 0;
            else
            {
                int minCuts = INT_MAX;
                for (i = j; i >= 1; i--)
                    if (t[i][j])
                        minCuts = min(minCuts, ans[i - 1]);

                ans[j] = minCuts + 1;
            }
        }

        return ans[length - 1];
    }
};

// time : O(n3) solution | Recursion + Memoization (TOP-DOWN) approach
class Solution
{
public:
    int t[501][501];

    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j)
    {

        if (i >= j)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        if (isPalindrome(s, i, j))
            return 0;

        int minP = INT_MAX, tempAns;
        for (int k = i; k <= j - 1; k++)
        {

            int p1, p2;
            (t[i][k] != -1) ? p1 = t[i][k] : p1 = solve(s, i, k);
            (t[k + 1][j] != -1) ? p2 = t[k + 1][j] : p2 = solve(s, k + 1, j);

            tempAns = p1 + p2 + 1;
            minP = min(minP, tempAns);
        }
        return t[i][j] = minP;
    }

    int palindromicPartition(string str)
    {
        memset(t, -1, sizeof(t));
        return solve(str, 0, str.size() - 1);
    }
};