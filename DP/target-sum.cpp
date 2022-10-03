// LEETCODE [MEDIUM] -> FASTEST SOLUTION

class Solution
{
public:
    int countWays(vector<int> nums, int sum)
    {
        int n = nums.size();
        int t[n + 1][sum + 1], i, j;

        memset(t, 0, sizeof(t));
        for (i = 0; i <= n; i++)
            t[i][0] = 1;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= sum; j++)
                if (nums[i - 1] > j || nums[i - 1] == 0) // We will skip 0 as we have already multiplied the final ans by (2^numberOfZeros)
                    t[i][j] = t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];

        return t[n][sum];
    }

    int findTargetSumWays(vector<int> &nums, int diff)
    {
        int range = 0, countZero = 0;
        for (auto i : nums)
        {
            range += i;
            if (!i)
                countZero++;
        }

        if (diff > range)
            return 0;

        if ((range - diff) % 2 != 0)
            return 0;

        int toFind = (range - diff) / 2;
        return pow(2, countZero) * countWays(nums, toFind);
    }
};