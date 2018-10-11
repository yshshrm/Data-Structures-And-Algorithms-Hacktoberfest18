// Method - Recursive Runtime O(2^n)

function fib(num) {
  if (num === 0) {
    return 0;
  }
  if (num === 1) {
    return 1;
  }
  return fib(num - 2) + fib(num - 1);
}

for (let i = 0; i < 20; i++) {
  console.log(fib(i));
}

// Method 2 - Memoization Runtime O(n), space O(n)
function fibDP(n) {
  let resultsCache = {};
  function innerFibonacci(n) {
    let result;
    if (resultsCache[n] !== undefined) {
      result = resultsCache[n];
    } else {
      if (n < 2) result = n;
      else result = innerFibonacci(n - 1) + innerFibonacci(n - 2);

      resultsCache[n] = result;
    }
    return result;
  }
  return innerFibonacci(n);
}

for (let i = 0; i < 20; i++) {
  console.log(i + ' : ' + fibDP(i));
}

// Method 3 - Runtime O(n)
function getNthFib(n) {
  let a = 0,
    b = 1,
    c;
  if (n === 0) {
    return a;
  }

  for (let i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

for (let i = 0; i < 20; i++) {
  console.log(i + ' : ' + getNthFib(i));
}
