#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Graph {
	int n;
	vector< pair<int, int> > *g;
	int *d;
	int *p;
	set<pair<int, int>> q;
	int s;
public:
	Graph(int n) {
		this->n = n;
		this->g = new vector< pair<int, int> >[n + 1];
		this->d = new int[n + 1];
		this->p = new int[n + 1];
	}
	void Initialize(int s) {
		for (int i = 1; i <= n; i++) {
			d[i] = INT_MAX;
			p[i] = -1;
		}
		d[s] = 0;
		p[s] = s;
	}
	void AddEdge(int u, int v, int w) {
		g[u].push_back(make_pair(w, v));
	}
	void Dijkstra(int s) {
		this->s = s;
		Initialize(s);
		q.insert(make_pair(d[s], s));
		while (!q.empty()) {
			int u = q.begin()->second;
			q.erase(q.begin());
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].second;
				int w = g[u][i].first;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					p[v] = u;
					q.insert(make_pair(d[v], v));
				}
			}
		}
	}
	void shortest() {
		for (int i = 1; i <= n; i++) {
			cout << s << " to " << i << " weight: " << d[i] << endl;
		}
	}
};

int main() {
	// Intial Graph
	Graph g(5);

	// Add vertex with weightd
	g.AddEdge(1, 2, 10);
	g.AddEdge(1, 4, 5);
	g.AddEdge(4, 5, 2);

	g.AddEdge(4, 3, 9);
	g.AddEdge(2, 3, 1);
	g.AddEdge(2, 4, 2);

	g.AddEdge(4, 2, 3);
	g.AddEdge(3, 5, 4);
	g.AddEdge(5, 3, 6);

	g.Dijkstra(1);
	g.shortest();
}