// Method 1 - Simple Recursion
class Solution
{
public:
    int checkSubsetSum(int n, int A[], int sum)
    {
        // base conditions
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;

        // choice diagram
        if (A[n - 1] > sum)
            return checkSubsetSum(n - 1, A, sum);
        else
            return checkSubsetSum(n - 1, A, sum - A[n - 1]) || checkSubsetSum(n - 1, A, sum);
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        return checkSubsetSum(N, arr, sum / 2);
    }
};

// Method 2 - Bottom-Up Approach [FASTEST]
class Solution
{
public:
    int checkSubsetSum(int n, int A[], int sum)
    {
        int i, j, t[n + 1][sum + 1];
        for (i = 0; i < n + 1; i++)
            for (j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = 0;
                if (j == 0)
                    t[i][j] = 1;
            }

        for (i = 1; i < n + 1; i++)
            for (j = 1; j < sum + 1; j++)
                if (A[i - 1] > j)
                    t[i][j] = t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j - A[i - 1]] || t[i - 1][j];

        return t[n][sum];
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        return checkSubsetSum(N, arr, sum / 2);
    }
};