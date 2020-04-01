#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l;
	while(scanf("%d",&l),l)
	{
		string S;
		cin>>S;
		int flag=1;
		vector<int >R,D;
		for(int i=0;i<S.length();i++)
		{	
			if(S[i]=='Z')
			{
				printf("0\n"),flag=0;
				break;
			}
			else if(S[i]=='R')
				R.push_back(i);
			else if(S[i]=='D')
				D.push_back(i);
		}
		if(flag)
		{
			int Min=INT_MAX;
			int i=0,j=0;
			while(i<R.size()&&j<D.size())
			{	
				Min=min(Min,abs(R[i]-D[j]));
				if(R[i]<D[j])
					i++;
				else 
					j++;
			}
			printf("%d\n",Min);
		}

	}
}			
