// Neatest Method LIS
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t;

        for (int i = 0; i < n; ++i)
        {
            auto it = lower_bound(begin(t), end(t), nums[i]);
            if (it == t.end())
                t.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return t.size();
    }
};

// O(nlogn) Method [DP + BINARY SEARCH]
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t = {nums[0]};

        for (int i = 1; i < n; ++i)
        {

            if (t.back() < nums[i])
            {
                t.push_back(nums[i]);
                continue;
            }

            int idx = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
            t[idx] = nums[i];
        }

        return (int)t.size();
    }
};

// O(n^2) Method [DP]
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), res = 1;
        vector<int> t(n, 1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    t[i] = max(t[i], 1 + t[j]);
                    res = max(res, t[i]);
                }
            }
        }

        return res;
    }
};