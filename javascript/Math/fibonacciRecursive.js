//  Do not run with large numbers.  Not an effective solution.

const nFibonacci = n => {
  // fibonacci sequence: 1 1 2 3 5 8 13 ...
  // return the nth number in the sequence
  // 0 + 1 = 1; 1 + 1 = 2; 1 + 2 = 3; 2 + 3 = 5
  //
  if (n <= 1) return n;
  return nFibonacci(n - 1) + nFibonacci(n - 2);
};
