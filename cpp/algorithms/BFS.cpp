#include <bits/stdc++.h>
//An implementation for Breadth First Search

using namespace std;

//Graph represented as adjacencies
void bfs(int s, vector<int> adj[], bool vis[]){
    queue<int> que;
    que.push(s);
    vis[s]=true;
    while(!que.empty()){
        int now=que.front();
        que.pop();
        cout << now << " ";
        //Now look for adjacents
        int size=adj[now].size();
        for(int i=0;i<size;i++){
            if(vis[adj[now][i]]==false){
                que.push(adj[now][i]);
                vis[adj[now][i]]=true;
            }
        }
    }
}
