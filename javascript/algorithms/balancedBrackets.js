/*
  Write a function balancedBrackets that receives a string of opening and closing brackets and determines whether or not the string's openers and closers are properly nested.

  The possible opening brackets are [, {, and (. The corresponding closers are ], }, and ).

  Examples:

      balancedBrackets('[]{}()');   // should return true
      balancedBrackets('[{[()]}]');   // should return true
      balancedBrackets('[({}}]');   // should return false
  
  Analyze the time and space complexity of your solution.
*/

const balancedBrackets = str => {
  // Your code here
  const brkts = { '{': '}', '(': ')', '[': ']' };
  const q = [];
  for (let b of str) {
    if (brkts[b]) {
      q.push(b);
    } else if (q.length) {
      b === brkts[q[q.length - 1]] ? q.pop() : null;
    }
  }
  return q.length === 0;
};
