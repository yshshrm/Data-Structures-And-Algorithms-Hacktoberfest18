// Complexity: O(n^3).
// Floyd Warshall algorithm that computes All Pair Shortest Path between nodes of a graph.

#include <iostream>
#include <queue>

using namespace std;

#define MAX 120
#define INF 500000000

int adjacency_matrix[MAX][MAX];

int main(){

  int number_of_nodes;

  scanf("%d",&number_of_nodes);

  // Initialize all distances as infinity.
  for(int i = 0;i <= number_of_nodes;++i){
    for(int j = 0;j <= number_of_nodes;++j){
      adjacency_matrix[i][j] = INF;
    }
  }

  int origin,destiny;
  int number_of_edges,cost;

  scanf("%d",&number_of_edges);
  // Store costs between neighbor nodes.
  for(int i = 0;i < number_of_edges;++i){
    scanf("%d %d %d",&origin,&destiny,&cost);
    adjacency_matrix[origin][destiny] = cost;
    adjacency_matrix[destiny][origin] = cost;	
  }

  for(int k =0;k < number_of_nodes;++k)
    for(int i =0;i<number_of_nodes;++i)
      for(int j = 0;j< number_of_nodes;++j)
        adjacency_matrix[i][j] = min(adjacency_matrix[i][j],adjacency_matrix[i][k] + adjacency_matrix[k][j]);

  int origin_node,destiny_node;

  scanf("%d %d",&origin_node,&destiny_node);

  printf("Total cost = %d\n",adjacency_matrix[origin_node][destiny_node]);

  return 0;
}
