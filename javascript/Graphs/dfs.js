/*This function expects an array of objects describing the edges of the graph formatted as: [{s, d}, .., {}]. Vertex indexing starts from 0.*/
function depthFirstSearch(inputArr, numberOfVertices) {
  var visited = [], queue = [];

  //initialize visited array
  for (var i = 0;i < numberOfVertices; i++) {
    visited.push(0);
  }

  // push in 0th vertex into queue.
  queue.push(0);

  while(queue.length !== 0) {
    var currentNode = queue.shift();

    if (visited[currentNode] !== 1) console.log(currentNode);

    visited[currentNode] = 1;

    for (var i = 0;i < numberOfVertices; i++) {
      if (visited[i] !== 1 && inputArr[currentNode][i] !== 0) {
        queue.unshift(i);
      }
    }
  }
}

module.exports = function(input, numberOfVertices) {
  var adj_matrix = [];

  // Initialize adjacency matrix.
  for (var i = 0;i < numberOfVertices; i++) {
    var row = [];
    for(var j = 0;j < numberOfVertices; j++) {
      row.push(0);
    }

    adj_matrix.push(row);
  }

  input.forEach((element) => {
    var sourceNode = element.s,
      destNode = element.d;

    adj_matrix[sourceNode][destNode] = 1;
    adj_matrix[destNode][sourceNode] = 1;
  });

  // Uncomment for adj matrix printing
  // for (var i = 0;i < numberOfVertices; i++) {
  //   for(var j = 0;j < numberOfVertices; j++) {
  //     console.log(i, j ,adj_matrix[i][j]);
  //   }
  // }

  depthFirstSearch(adj_matrix, numberOfVertices);
}