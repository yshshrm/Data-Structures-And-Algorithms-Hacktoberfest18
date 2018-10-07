import java.io.*;
import java.util.*;
public class Graph_BFS{
	public static void main(String ar[]){
		int n = 10; // n-Number of Vertices.
		BFS g1 = new BFS(n	);
		g1.addEdge(1,2);
		g1.addEdge(2,3);
		g1.addEdge(1,5);
		g1.addEdge(2,4);
		g1.search(2);
		System.out.println(g1.distOf(3));
		System.out.println(g1.wasVisited(5));
	}
}
class BFS{
	List<Integer>[] Adj;
	int N;
	int distance[];
	boolean color[];
	public BFS(int N){
		this.N = N;
		Adj = new ArrayList[N+1];
		distance = new int[N+1];
		for(int i=0;i<=N;i++) distance[i]=0;
	}
	void addEdge(int a,int b){
		if(Adj[a]==null) Adj[a] = new ArrayList<Integer>();
		Adj[a].add(b);
		if(Adj[b]==null) Adj[b] = new ArrayList<Integer>();
		Adj[b].add(a);
	}
	void search(int source){
		color = new boolean[N+1];
        color[source]=true;
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(source);
		distance[source]=0;
        while(!q.isEmpty()){
            int u = q.poll();
            for(int v:Adj[u]){
                if(!color[v]){
                    color[v]=true;
					distance[v]=distance[u]+1;
                    q.add(v);
                }
            }
        }
	}
	int distOf(int v){
		return distance[v];
	}
	boolean wasVisited(int v){
		return color[v];
	}
}
