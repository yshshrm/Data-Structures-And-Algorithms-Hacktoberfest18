#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char c[n][101];
    int a[n],k[n];
    for(int i=0;i<n;i++)
    {
        scanf(" %s",c[i]);

    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<i;j++)
           {

        if((strcmp(c[i],c[j])==0))
            {
              k[i]=1;
              break;
            }

    }
    }
    for(int i=0;i<n;i++)
        if(k[i]==1)
        printf("YES\n");
    else
        printf("NO\n");
}
