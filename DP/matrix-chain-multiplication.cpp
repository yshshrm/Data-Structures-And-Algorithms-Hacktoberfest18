#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MCMSolve(vector<int> A, int i, int j, vector<vector<int>> t)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];

    int tempAns, k, minCost = INT_MAX;
    for (k = i; k <= j - 1; k++)
    {
        tempAns = MCMSolve(A, i, k, t) + MCMSolve(A, k + 1, j, t) + A[i - 1] * A[k] * A[j];
        minCost = min(minCost, tempAns);
    }

    return t[i][j] = minCost;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        vector<vector<int>> t(101, vector<int>(101, -1));
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A[i] = x;
        }

        cout << MCMSolve(A, 1, n - 1, t) << "\n";
    }
    return 0;
}