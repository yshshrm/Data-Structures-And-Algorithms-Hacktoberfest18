#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	string s,t;
	cin>>s>>t;
	
	
	int l1,l2;
	l1=s.length();
	l2=t.length();
	string ans="";
	int dp[l1+1][l2+1];
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			
			}
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}

	}
	for(int i=0;i<l2;i++)
	{
		if(dp[l1][i]!=dp[l1][i+1])
			ans=ans+t[i+1];

	}
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<dp[l1][l2]<<endl;
	cout<<ans<<endl;

	return 0;
}