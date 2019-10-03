#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,p,tp,s=0;
	scanf("%d%d%d",&n,&m,&p);
	while(n||m||p)
	{
		//printf("[%d %d %d]\n",n,m,p);
		int Max=0,flag=0;
		tp=0;
		int A[n+1],B[n+1];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&A[i]);
			B[i]=0;
		}
		for(int i=0;i<m;i++)
		{
			int temp;
			scanf("%d",&temp);
			B[temp]++;
			if(B[temp]%2)
				tp+=A[temp];
			else
				tp-=A[temp];
			Max=max(tp,Max);
			if(tp>p)
			{
				flag=1;
			}

		}
		s++;
		printf("Sequence %d\n",s);
		if(flag)
			printf("Fuse was blown.\n\n");
		else
		{
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",Max);
		}
		scanf("%d%d%d",&n,&m,&p);
	}	
	return 0;
}