#include <bits/stdc++.h>
using namespace std;
#define x output
int V=1000;
void dfs__2d(int **input,int *visited,vector<int> &temp,int node){
    visited[node]=1;
    temp.push_back(node);
    for(int i=0;i<V;i++){
        if(!visited[i]&&input[node][i]){
            dfs__2d(input,visited,temp,i);
        }
    }
    
}

void dfs(const vector<vector<int> > &input,vector<bool> &visited,vector<int> &temp,int node ){
    visited[node]=true;
    temp.push_back(node);
    for(auto x:input[node]){
        if(!visited[x]){
            dfs(input,visited,temp,x);
        }
    }
}

int main()
{
  int  E, tempX, tempY;
  cin >> V >> E;
  vector< vector<int> > input(V);
    
  for(int i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      input[u].push_back(v);
      input[v].push_back(u);
  }
   
  vector<bool> visited(V,false);    
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector< int > output;
            dfs(input,visited,output,i);
            sort(x.begin(),x.end());
            for(auto z:x){
            cout<<z<<" ";
            }
        cout<<endl;
        }
    }
 

  return 0;
}

int main_with_2d_array()
{
  int  E, tempX, tempY;
  cin >> V >> E;
  int ** input=new int*[V];
  for(int i=0;i<V;i++){
      input[i]=new int[V]();
  }
    
  for(int i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      input[u][v]=1;
      input[v][u]=1;
  }
   
    int *visited= new int[V]();
    
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector< int > output;
            dfs__2d(input,visited,output,i);
            sort(x.begin(),x.end());
            for(auto z:x){
            cout<<z<<" ";
        }
        //    x.clear();
        cout<<endl;
        }
    }
 

  return 0;
}
