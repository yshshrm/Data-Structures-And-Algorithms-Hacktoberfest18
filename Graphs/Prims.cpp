#include <bits/stdc++.h>
using namespace std;

int getmin(vector<int> &visited,vector<int> &wt){
    int minvertex=-1;
    for(int i=0;i<visited.size();i++){
        if(!visited[i]&&((minvertex==-1)||(wt[minvertex]>wt[i]))){
                minvertex=i;
        }
    }
           return minvertex;
}

void prim(const vector< vector<pair<long,long> > > &edges){
    int V=edges.size();
      vector<int> parent(V,0),visited(V,0),wt(V,INT_MAX);
       int source=0;
       wt[source]=0;
        
        for(int i=0;i<V;i++){
            
            //getminvertex
            int minvertex=getmin(visited,wt);
            visited[minvertex]=1;
            
            //explore all neighbours of min vertex & update wt and parent acc;
            for(auto x:edges[minvertex]){
                if(wt[x.first]>x.second&&!visited[x.first]){
                    wt[x.first]=x.second;
                    parent[x.first]=minvertex;
                }   
            }
            
        }
    
    //printing work
    for(int i=1;i<V;i++){
      cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<wt[i]<<endl;
  }
    
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  vector< vector<pair<long,long> > > edges(V);
  // vector< pair<int,pair<int,int> > > output;
  for(int i=0;i<E;i++){
      long u,v,w;
      cin>>u>>v>>w;
      if(w<=0)w=INT_MAX;
      edges[u].push_back({v,w});
      edges[v].push_back({u,w});
  }
 
   prim(edges); 
  return 0;
}
