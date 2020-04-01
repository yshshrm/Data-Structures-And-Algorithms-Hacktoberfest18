// A C++ program to demonstrate adjacency list 
// representation of graphs using sets 
#include <bits/stdc++.h> 
using namespace std; 

struct Graph { 
	int V; 
	set<int, greater<int> >* adjList; 
}; 

// A utility function that creates a graph of V vertices 
Graph* createGraph(int V) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 

	// Create an array of sets representing 
	// adjacency lists. Size of the array will be V 
	graph->adjList = new set<int, greater<int> >[V]; 

	return graph; 
} 

// Adds an edge to an undirected graph 
void addEdge(Graph* graph, int src, int dest) 
{ 
	// Add an edge from src to dest. A new 
	// element is inserted to the adjacent 
	// list of src. 
	graph->adjList[src].insert(dest); 

	// Since graph is undirected, add an edge 
	// from dest to src also 
	graph->adjList[dest].insert(src); 
} 

// A utility function to print the adjacency 
// list representation of graph 
void printGraph(Graph* graph) 
{ 
	for (int i = 0; i < graph->V; ++i) { 
		set<int, greater<int> > lst = graph->adjList[i]; 
		cout << endl << "Adjacency list of vertex "
			<< i << endl; 

		for (auto itr = lst.begin(); itr != lst.end(); ++itr) 
			cout << *itr << " "; 
		cout << endl; 
	} 
} 

// Searches for a given edge in the graph 
void searchEdge(Graph* graph, int src, int dest) 
{ 
	auto itr = graph->adjList[src].find(dest); 
	if (itr == graph->adjList[src].end()) 
		cout << endl << "Edge from " << src 
			<< " to " << dest << " not found."
			<< endl; 
	else
		cout << endl << "Edge from " << src 
			<< " to " << dest << " found."
			<< endl; 
} 

// Driver code 
int main() 
{ 
	// Create the graph given in the above figure 
	int V = 5; 
	struct Graph* graph = createGraph(V); 
	addEdge(graph, 0, 1); 
	addEdge(graph, 0, 4); 
	addEdge(graph, 1, 2); 
	addEdge(graph, 1, 3); 
	addEdge(graph, 1, 4); 
	addEdge(graph, 2, 3); 
	addEdge(graph, 3, 4); 

	// Print the adjacency list representation of 
	// the above graph 
	printGraph(graph); 

	// Search the given edge in the graph 
	searchEdge(graph, 2, 1); 
	searchEdge(graph, 0, 3); 

	return 0; 
} 

