#include <bits/stdc++.h>
using namespace std;

vector<int> dijkastra(vector<int> g[],int src,int V)
{
    vector<int> dist(V,INT_MAX);
    dist[src]=0;

    vector<bool> fin(V,false);

    for(int count=0;count<V-1;count++)
    {
        int u=-1;
        for(int i=0;i<V;i++)
        {
            if(fin[i]!=true && (u==-1||dist[i]<dist[u]))
            u=i;
        }
        fin[u]=true;
        for(int v=0;v<V;v++)
        {
            if(g[u][v]!=0 && fin[v]==false)
            {
                dist[v]=min(g[u][v]+dist[u] , dist[v]);
            }
        }
    }
    return dist;
}

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;

    int src;
    cin>>src;

    vector<int> g[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            g[i].push_back(x);
        }
    }
    
    vector<int> dist(n);
    dist=dijkastra(g,src,n);

    for(int i=0;i<n;i++)
    cout<<dist[i]<<" ";
}