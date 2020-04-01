const graph = new Graph(Graph.UNDIRECTED);

const [first] = graph.addEdge(1, 2);
graph.addEdge(1, 3);
graph.addEdge(1, 4);
graph.addEdge(5, 2);
graph.addEdge(6, 3);
graph.addEdge(7, 3);
graph.addEdge(8, 4);
graph.addEdge(9, 5);
graph.addEdge(10, 6);

bfsFromFirst = graph.bfs(first);

bfsFromFirst.next().value.value; // 1
bfsFromFirst.next().value.value; // 2
bfsFromFirst.next().value.value; // 3
bfsFromFirst.next().value.value; // 4