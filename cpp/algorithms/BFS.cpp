#include <iostream>
#include <queue>
using namespace std;


const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int main() {
	
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        u = q.front();
        q.pop();
        
        cout<<"Visiting "<<u<<endl;
        for(int i=0;i<adj[u].size();++i){
            v = adj[u][i];
            if(!vis[v])
                q.push(v);
        }
        
    }
	return 0;

}
