// Complexity: O(n^2)                                                              
// Test if a given graph is a Bicolorable Graph.                                  
// A Bipartite Graph or Bicolorable Graph, is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 210
bool bicolorable = true;

vector<int> adjacency_list[MAX];
int colors[MAX];

// Try to assign colors to nodes, so that no node share the same color with its neighbor;
void dfs(int node,int color){

  if(not bicolorable) return;

  colors[node] = color;

  for (auto it : adjacency_list[node])
  {
    if(colors[it] == -1){
      dfs(it,1 - color);
    }else if(colors[it] == colors[node]){
      bicolorable = false;
      break;
    }
  }

}

int main(){

  // Initalize all colors position with -1 values. That means no node has been colored yet;
  memset(colors,-1,sizeof colors);

  int number_of_adjancencies;
  scanf("%d",&number_of_adjancencies);

  int origin,destiny;

  // Fill adjancencies between nodes
  for(int i = 0;i < number_of_adjancencies;++i){
    scanf("%d %d",&origin,&destiny);
    adjacency_list[origin].push_back(destiny);
    adjacency_list[destiny].push_back(origin);
  }

  dfs(0,0);

  printf("%s\n",(bicolorable?"THIS GRAPH IS BICOLORABLE.":"THIS GRAPH IS NOT BICOLORABLE."));

  return 0;

}
