#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int lcm(int arr[], int n)
{
    int result = arr[0];

    for (int i = 1; i < n; i++)
        result = (arr[i] * result) / gcd(arr[i], result);

    return result;
}

int main()
{
    int n = 6;
    int arr[6] = {2, 3, 6, 5, 9, 12};
    cout << lcm(arr, n);
    return 0;
}
