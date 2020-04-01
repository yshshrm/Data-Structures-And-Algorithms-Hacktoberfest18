#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int> > &adj,vector<bool> &visited,int node){
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(!visited[x]){
            cout<<x<<" ";
            visited[x]=true;
        }
        for(auto itr:adj[x]){
            if(!visited[itr])q.push(itr);            
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

//faaltu ki taaki code chljaaye
    for(int i=0;i<V;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<bool> visited(V,false);
    
    bfs(adj,visited,0);
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}
