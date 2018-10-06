// note: this solution will give you the number at index n with O(N)
function fibonacci(n) {
  let a = 1;
  let b = 0;
  let tempNum;

  while (n >= 0) {
    tempNum = a;
    a = a + b;
    b = tempNum;
    n--;
  }

  return b;
}
