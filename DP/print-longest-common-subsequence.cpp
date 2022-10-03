#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string lcs(int x, int y, string s1, string s2)
{
    int t[x + 1][y + 1], i, j;
    memset(t, 0, sizeof(t));

    for (i = 1; i <= x; i++)
        for (j = 1; j <= y; j++)
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);

    i = x;
    j = y;

    string output;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            output.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(output.begin(), output.end());
    return output;
}

int main()
{
    string s1 = "ABCDEF", s2 = "ABXYDVEYF";
    cout << lcs(s1.size(), s2.size(), s1, s2);
}