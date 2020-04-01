#include <bits/stdc++.h>
using namespace std;

int getmin(vector<long> &dist,vector<long> &visited){
    int min=-1;
    for(int i=0;i<dist.size();i++){
        if(!visited[i]&&(min==-1||dist[i]<dist[min])){
            min=i;
        }
    }
    return min;
}

void dijkstra(const vector< vector<pair<long,long> > > &edges,int source){
    int V=edges.size();
    vector<long> visited(V,0),dist(V,INT_MAX);
    dist[source]=0;
    
    for(int i=0;i<V;i++){
        
        int mindist=getmin(dist,visited);
        visited[mindist]=1;
        
        for(auto x:edges[mindist]){
            if(!visited[x.first]&&dist[x.first]>x.second+dist[mindist]){
                dist[x.first]=x.second+dist[mindist];
            }
        }    
        
    }
    
    for(int i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  vector< vector<pair<long,long> > > edges(V);
  for(int i=0;i<E;i++){
      long u,v,w;
      cin>>u>>v>>w;
      if(w<=0)w=INT_MAX;
      edges[u].push_back({v,w});
      edges[v].push_back({u,w});
  }
   int source=0;
   dijkstra(edges,source); 

  return 0;
}
