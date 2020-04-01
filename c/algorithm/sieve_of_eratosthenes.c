//Prime numbers using Sieve of Eratosthenes
#include <stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int prime[100000]={0};
    prime[0] = 1;
    prime[1] = 1;
    for(int i=2;i<=ceil(sqrt(n));i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j <= n;j++)
               prime[i*j] = 1;
        }
    }
    for(int j=0;j<=n;j++)
    {
        if(prime[j]==0)
        printf("%d ",j);
    }
    return 0;
}

