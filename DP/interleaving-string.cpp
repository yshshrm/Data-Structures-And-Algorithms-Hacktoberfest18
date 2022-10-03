// BFS APPROACH
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();

        if (m + n != (int)s3.size())
            return false;

        bool vis[m + 1][n + 1];
        memset(vis, 0, sizeof(vis));

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (q.size())
        {
            auto [i, j] = q.front();
            q.pop();

            if (vis[i][j] == true)
                continue;

            if (i == m && j == n)
                return true;

            if (s1[i] == s3[i + j] && !vis[i + 1][j])
                q.push({i + 1, j});

            if (s2[j] == s3[i + j] && !vis[i][j + 1])
                q.push({i, j + 1});

            vis[i][j] = true;
        }

        return false;
    }
};

// DFS Approach
class Solution
{
    bool vis[101][101] = {};
    bool solve(string &s1, string &s2, string &s3, int i, int j)
    {
        vis[i][j] = true;

        if (i == s1.size() && j == s2.size())
            return true;

        int ans = false;
        if (i < s1.size() && s1[i] == s3[i + j] && !vis[i + 1][j])
            ans = ans || solve(s1, s2, s3, i + 1, j);
        if (j < s2.size() && s2[j] == s3[i + j] && !vis[i][j + 1])
            ans = ans || solve(s1, s2, s3, i, j + 1);

        return ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();

        if (m + n != (int)s3.size())
            return false;

        return solve(s1, s2, s3, 0, 0);
    }
};

// DP
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();

        if (m + n != s3.size())
            return false;

        bool dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        // empty strings
        dp[0][0] = true;

        // 1st row
        for (int i = 1; i <= n; ++i)
        {
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        }

        // 1st col
        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // main
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                dp[i][j] = dp[i][j] || dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            }
        }

        return dp[m][n];
    }
};