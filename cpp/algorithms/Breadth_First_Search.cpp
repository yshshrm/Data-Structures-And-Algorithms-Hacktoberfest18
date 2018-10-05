// Created by Jaimin Chaudhari
// Date : 6-10-2018
// Follow me on Github : https://github.com/jaimin257


#include<bits/stdc++.h>

#define ll long long

using namespace std;

void BFS(ll source, vector<ll>adj[] , vector<ll>visited , vector<ll>level);

int main()
{
    ll n,m,v1,v2,x;
    cout<<"Enter number of vertices and edges in the graph : ";
    cin>>n>>m;
    vector <ll> adj[n+1];
    vector <ll> visited(n+1,0);
    vector <ll> level(n+1,0);
    cout<<"enter edges of the graph.\n";
    for(ll i=0;i<m;i++)
    {
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    cout<<"Enter source vertex for Graph : ";
    cin>>x;
    BFS(x,adj,visited,level);
    cout<<endl;
    return 0;
}

void BFS(ll source, vector<ll>adj[] , vector<ll>visited , vector<ll>level)
{
    queue <int> q;
    q.push(source);
    visited[source] = 1;
    level[source] = 1;
    while(!q.empty())
    {
        ll v = q.front();
        cout<<v<<" ";
        q.pop();
        for(ll i=0;i<adj[v].size();i++)
        {
            if(visited[adj[v][i]] == 0)
            {
                q.push(adj[v][i]);
                visited[adj[v][i]] = 1;
                level[adj[v][i]] = level[v] + 1;
            }
        }
    }
}