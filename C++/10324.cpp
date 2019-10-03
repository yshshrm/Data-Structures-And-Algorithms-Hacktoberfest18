#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int c=0;
	char S[1000001];
	while(scanf("%s",S)!=EOF)
	{
		int l=strlen(S);
		c++;
		printf("Case %d:\n",c);
		int i,A[l];
		memset(A,0,sizeof(A));
		for(i=1;i<l;i++)
		{
			if(S[i]!=S[i-1])
			{
				for(int j=i-1;j>-1&&A[j]==0;j--)
					A[j]=i;
			}
		}
		for(int j=i-1;j>-1&&A[j]==0;j--)
			A[j]=i;
		int t,a,b;
		scanf("%d%*c",&t);
		while(t--)
		{
			scanf("%d%d%*c",&a,&b);
			if(A[ min(a,b) ]> max(b,a) )
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}