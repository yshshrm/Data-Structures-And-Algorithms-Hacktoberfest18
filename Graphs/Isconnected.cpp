#include <bits/stdc++.h>
using namespace std;
void dfs(const vector< vector<int> > &adj,vector<bool> &visited,int node){
    visited[node]=1;
    for(auto x:adj[node]){
        if(!visited[x]){
            dfs(adj,visited,x);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector< vector<int> > adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(V,0);
    dfs(adj,visited,0);//O(E)~O(N^2)
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            cout<<"false";return 0;
        }
    }
    
    
    cout<<"true";return 0;
    
}
