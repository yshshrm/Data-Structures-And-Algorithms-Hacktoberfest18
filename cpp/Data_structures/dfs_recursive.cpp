#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define N 13

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
	public:
	// A array of vectors to represent adjacency list
	vector<int> adjList[N];
	
	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the undirected graph
		for (int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

// Function to perform DFS Traversal
int DFS(Graph const &graph, int v, vector<bool> &discovered)
{
	// mark current node as discovered
	discovered[v] = true;
	
	// print current node
	cout << v << " ";
	
	// do for every edge (v -> u)
	for (int u : graph.adjList[v])
	{
		// u is not discovered
		if (!discovered[u])
			DFS(graph, u, discovered);
	}
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = { 
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, 
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11} 
	};

	// create a graph from given edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// Do DFS traversal from all undiscovered nodes to 
	// cover all unconnected components of graph
	for (int i = 1; i < N; i++)
		if (discovered[i] == false)
			DFS(graph, i, discovered);

	return 0;
}
