#include <bits/stdc++.h>
using namespace std;
vector<int> v[20010];
int dis[10010];
int i,j,k,n,m,q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q>>n;
    for(i=0;i<n+2;i++)
    {
        cin>>j>>k>>m;
        v[i].push_back(j);
        v[i].push_back(k);
        v[i].push_back(m);
    }
    dis[0]=0;
    for(i=0;i<n-1;i++)
    {
    	int j=0;
    	while(v[j].size()!=0)
    	{
    		if( dis[v[j][0]] + v[j][2] < dis[v[j][1]] )
    		{
    			dis[v[j][1]] = dis[v[j][0]] + v[j][2];
    		}
    		j++;
    	}
    }
    cout<<"vertex distance from source\n";
    for(i=0;i<q;i++)
    	cout<<i<<dis[i]<<endl;
    return 0;
}