/*
* Program to compute list of prime numbers
* upto a given limit using Sieve of Eratosthenes
* Language: C
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define ll long long

void sieve(ll int n)
{
    bool a[n+1];
    memset(a,1,sizeof(a));
    ll int count = 0;
    for(ll int i=2; i*i<=n; i++)
    {
        if(a[i])
        {
            for(ll int j=i*i; j<=n; j+=i)
                a[j] = 0;
        }
    }
    for(ll int i=2; i<=n; i++)
        if(a[i]) printf("%lld ", i);
}

int main()
{
    ll int n;
    scanf("%lld", &n);
    sieve(n);
    printf("\n");
}
