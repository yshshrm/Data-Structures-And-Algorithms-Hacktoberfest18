// This file initializes the input to graph algorithms and runs them. Run this file as follows: node index.js

const dfs = require('./dfs.js'),
  bfs = require('./bfs.js');

/*A sample graph: 
        0
      /   \
     1     2
     |     |
     4     3
*/
var input = [{s:0,d:1}, {s:0,d:2}, {s:1,d:4}, {s:2,d:3}];

console.log("BFS:", bfs(input, 5));
console.log("DFS", dfs(input, 5));