/*
  Let's say a robot is located at the top-left corner of an n x n grid. 
  The robot can move either up, down, left, or right, one space at a time. 
  It also cannot visit the same spot twice. The robot is trying to reach 
  the bottom-right corner of the grid.

  Write a function to count the number of ways that the robot can reach 
  the bottom-right corner of the grid. Your function should receive n 
  (the size of the grid) as a parameter.

  A board can be generated using this function:
*/

function makeBoard(n) {
  let board = [];
  for (let i = 0; i < n; i++) {
    board.push([]);
    for (let j = 0; j < n; j++) {
      board[i].push(false);
    }
  }
  board.toggle = (i, j) => {
    board[i][j] = !board[i][j];
  };
  board.hasBeenVisited = (i, j) => {
    return board[i][j];
  };
  return board;
}

// Solution below

function pathCount(n) {
  const board = makeBoard(n);
  let count = 0;
  const move = (x, y) => {
    if (x === n - 1 && y === n - 1) {
      count++;
      return;
    }

    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (board.hasBeenVisited(x, y)) return;

    board.toggle(x, y);
    move(x - 1, y);
    move(x + 1, y);
    move(x, y - 1);
    move(x, y + 1);
    board.toggle(x, y);
  };
  move(0, 0);
  return count;
}

module.exports = { makeBoard, pathCount };
