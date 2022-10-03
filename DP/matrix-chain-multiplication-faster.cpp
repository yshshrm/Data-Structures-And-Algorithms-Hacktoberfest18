#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int t[101][101];
    int MCMSolve(vector<int> A, int i, int j)
    {
        if (i >= j)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];

        int tempAns, k, minCost = INT_MAX;
        for (k = i; k <= j - 1; k++)
        {
            int p1, p2;
            if (t[i][k] != -1)
                p1 = t[i][k];
            else
                p1 = MCMSolve(A, i, k);

            if (t[k + 1][j] != -1)
                p2 = t[k + 1][j];
            else
                p2 = MCMSolve(A, k + 1, j);

            tempAns = p1 + p2 + A[i - 1] * A[k] * A[j];
            minCost = min(minCost, tempAns);
        }

        return t[i][j] = minCost;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(t, -1, sizeof(t));
        vector<int> A;
        for (int i = 0; i < N; i++)
        {
            A.push_back(arr[i]);
        }
        return MCMSolve(A, 1, N - 1);
    }
};