#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,p,s=0;
	while(scanf("%d%d%*c",&n,&p),n||p)
	{
		s++;
		if(s>1)
			printf("\n");
		string temp;
		double Max=0;
		int index;
		pair<string,double > P[p];
		for(int i=0;i<n;i++)
		{
			getline(cin,temp);
			//cout<<i<<" "<<temp<<endl;
		}
		for(int i=0;i<p;i++)
		{
			getline(cin,temp);
			double d;
			int r;
			scanf("%lf%d%*c",&d,&r);
			//cout<<temp<<" "<<d<<" "<<r<<endl;
			P[i]={temp,d};
			if(Max<(double)r/n)
			{
				
				Max=(double)r/n;
				index=i;
			}
			else if(Max==(double)r/n)
			{
				if(P[index].second>d)
					index=i;
			}
			for(int j=0;j<r;j++)
			{	
				getline(cin,temp);
				//cout<<temp<<endl;
			}
		}
		printf("RFP #%d\n",s);
		cout<<P[index].first<<endl;
	}
}