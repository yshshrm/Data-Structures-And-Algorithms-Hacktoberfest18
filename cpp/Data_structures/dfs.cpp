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

// Perform iterative DFS on graph g starting from vertex v	
int iterativeDFS(Graph const &graph, int v)
{
	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// create a stack used to do iterative DFS
	stack<int> stack;
 
	// push the source node into stack
	stack.push(v);
 
	// run till stack is not empty	
	while (!stack.empty())
	{
		// Pop a vertex from stack
		v = stack.top();
		stack.pop();
 
		// if the vertex is already discovered yet, 
		// ignore it
		if (discovered[v])
			continue;
 
		// we will reach here if the popped vertex v 
		// is not discovered yet. We print it and process 
		// its undiscovered adjacent nodes into stack
		discovered[v] = true;
		cout << v << " ";
		
		// do for every edge (v -> u)
		// we use reverse iterator (Why?)
		for (auto it = graph.adjList[v].rbegin(); 
			it != graph.adjList[v].rend(); ++it)
		{
			int u = *it;
			if (!discovered[u])
				stack.push(u);
		}
	}
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {  
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, 
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
		// , {6, 9} // introduce cycle 
	};
	
	// create a graph from given edges
	Graph graph(edges);
	
	// Do iterative DFS traversal from vertex 1
	iterativeDFS(graph, 1);
	
	return 0;
}
