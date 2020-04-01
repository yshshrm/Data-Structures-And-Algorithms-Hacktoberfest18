#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,c=0;
	while(scanf("%d\n",&k)!=EOF)
	{
		c++;
		if(c>1)
		{
			cout<<endl;
		}

		string S[k];
		unordered_map<string,int >umap;
		for(int i=0;i<k;i++)
		{
			cin>>S[i];
			umap.insert({S[i],0});
		}

		for(int i=0;i<k;i++)
		{
			int a,b;
			string temp;
			cin>>temp>>a>>b;
			if(b)
			{
				umap[temp]-=(a/b)*b;
			}	
			for(int j=0;j<b;j++)
			{
				cin>>temp;
				umap[temp]+=a/b;
			}
		}

		for(int i=0;i<k;i++)
		{
			cout<<S[i]<<" "<<umap[S[i]]<<endl;
		}

	}
}