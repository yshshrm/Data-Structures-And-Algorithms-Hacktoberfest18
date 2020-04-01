
//adj is the graph represented in adjacency lists

//This function finds the distances of all nodes from the node x using BFS

function findDistanceWithBFS(x) {
	var q = Array();
	var visited = Array(N);
	var distance = Array(N);


	visited[x] = true;
	distance[x] = 0;
	q.push(x);
	while (q.length>0) {
		int s = q.shift();
		adj[s].forEach(u=>{
			if (!visited[u]) {
				visited[u] = true;
				distance[u] = distance[s]+1;
				q.push(u);				
			}	
		}) 
	}

	return distance;
}