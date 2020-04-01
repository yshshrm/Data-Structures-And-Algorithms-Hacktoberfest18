#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k),n!=0)
	{
		bool flag=true;
		int A[10000];
		memset(A,0,sizeof(A));
		int temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			A[temp]++;
		}
		for(int i=0;i<k;i++)
		{
			int count=0;
			int c,r;
			scanf("%d%d",&c,&r);
			for(int j=0;j<c;j++)
			{
				scanf("%d",&temp);
				if(A[temp])
					count++;
			}
			if(count<r)
				flag=false;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}
