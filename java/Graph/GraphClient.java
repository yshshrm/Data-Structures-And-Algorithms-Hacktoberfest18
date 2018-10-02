package Graph;



public class GraphClient {

	public static void main(String[] args) throws Exception {

		Graph graph = new Graph();
		graph.addVertex("A");
		graph.addVertex("B");
		graph.addVertex("C");
		graph.addVertex("D");
		graph.addVertex("E");
		graph.addVertex("F");
		graph.addVertex("G");
		graph.addEdge("A", "B", 10);
		graph.addEdge("A", "D", 40);
		graph.addEdge("B", "C", 10);
		graph.addEdge("C", "D", 10);
		graph.addEdge("D", "E", 5);
		graph.addEdge("E", "F", 2);
		graph.addEdge("E", "G", 6);
		graph.addEdge("F", "G", 3);

		// graph.addEdge("A", "B", 6);
		// graph.addEdge("A", "E", 4);
		// graph.addEdge("A", "F", 5);
		// graph.addEdge("E", "F", -3);
		// graph.addEdge("B", "C", 2);
		// graph.addEdge("C", "D", 2);
		// graph.addEdge("D", "C", 1);
		// graph.addEdge("F", "D", 4);

		// graph.addEdge("A", "B", 5);
		// graph.addEdge("B", "C", -2);
		// graph.addEdge("A", "C", 4);
		//
		// graph.addEdge("A", "B", 1);
		// graph.addEdge("B", "C", 2);
		// graph.addEdge("C", "D", 2);
		// graph.addEdge("D", "B", 6);

		// graph.display();
		// graph.prims().display();

		// System.out.println(graph.Dijkstra("A"));
	
		System.out.println(graph.BellmanFord("A"));

	}

}
