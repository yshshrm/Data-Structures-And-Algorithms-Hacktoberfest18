#include <bits/stdc++.h>
using namespace std;
vector<int> *dfs(const  vector< vector<int> > &adj,vector<bool> &visited,int curnode,int targetnode){
    visited[curnode]=true;
    // cout<<curnode<<" : ";
  //  cout<<curnode<<" "<<targetnode<<endl;
    if(curnode==targetnode){
        vector<int> *V=new vector<int>;
        (*V).push_back(targetnode);
        return V;
    }
    
    for(int i=0;i<adj[curnode].size();i++){
        long x=adj[curnode][i];
        // cout<<endl<<x<<" "<<visited[x]<<endl;
        if(!visited[x]){
         vector<int> *V=dfs(adj,visited,x,targetnode);
        if(V!=NULL){
           (*V).push_back(curnode);
            return V;
        }
    }
}
    
    vector<int> *temp=NULL;
    return temp;
    
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  vector< vector<int> > adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int v1,v2;
    cin>>v1>>v2;
    vector<bool> visited(V,0);
    
    for(int i=0;i<adj.size();i++){
      sort(adj[i].begin(),adj[i].end());//I am doing this because in 2d array vertices are in sorted form 
        // for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";cout<<endl;
    }
    

   vector<int> *v=dfs(adj,visited,v1,v2);

   if(v!=NULL)   for(int i=0;i<(*v).size();i++){  cout<<(*v)[i]<<" ";   }
     
    return 0;
}
