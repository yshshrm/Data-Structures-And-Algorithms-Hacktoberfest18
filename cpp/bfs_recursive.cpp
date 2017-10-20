#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Number of vertices in the graph
#define N 15

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
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

// Perform BFS recursively on graph
void recursiveBFS(Graph const &graph, queue<int> &q, 
					vector<bool> &discovered)
{
	if (q.empty())
		return;

	// pop front node from queue and print it
	int v = q.front();
	q.pop();
	cout << v << " ";

	// do for every edge (v -> u)
	for (int u : graph.adjList[v])
	{
		if (!discovered[u])
		{
			// mark it discovered and push it into queue
			discovered[u] = true;
			q.push(u);
		}
	}

	recursiveBFS(graph, q, discovered);
}

// Recursive C++ implementation of Breadth first search
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9}, 
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
		// vertex 0, 13 and 14 are single nodes
	};

	// create a graph from edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);

	// create a queue used to do BFS
	queue<int> q;

	// Do BFS traversal from all undiscovered nodes to
	// cover all unconnected components of graph
	for (int i = 0; i < N; i++) {
		if (discovered[i] == false)
		{
			// mark source vertex as discovered
			discovered[i] = true;

			// push source vertex into the queue
			q.push(i);

			// start BFS traversal from vertex i
			recursiveBFS(graph, q, discovered);
		}
	}

	return 0;
}
