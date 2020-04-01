#include<bits/stdc++.h>
using namespace std;
void factorize(int n)
{
    int i;
    while (n % 2 == 0)
        n = n / 2, printf("%d ",2);
    for (i = 3; i * i <= n; i+=2)
        while (n % i == 0)
            n = n / i, printf("%d ",i);
    if (n>2)
        printf("%d",n);
}
int main()
{
    int n;
    cin>>n;
    factorize(n);
}