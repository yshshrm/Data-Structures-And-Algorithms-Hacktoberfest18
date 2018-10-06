// note: solution will give you number at index n with complexity of O(2^N).
// for better performance apply other techniques like memoization
function fibonacciRecursive(n) {
  if (n < 2) {
    return n;
  }

  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
