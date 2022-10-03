#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxVal(vector<int> price, vector<int> length, int n)
{
    int t[n + 1][n + 1], i, j;
    memset(t, 0, sizeof(t));

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (length[i - 1] > j)
                t[i][j] = t[i - 1][j];
            else
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);

    return t[n][n];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> price(n), length(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            price[i] = x;
            length[i] = i + 1;
        }
        cout << getMaxVal(price, length, n) << "\n";
    }
    return 0;
}