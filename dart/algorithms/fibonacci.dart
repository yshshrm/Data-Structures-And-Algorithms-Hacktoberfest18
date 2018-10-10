import 'dart:core';

int fibonacci(int n) { // find n th fibonacci
  if (n == 0 || n == 1) return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

var result = fibonacci(20);

void main(){
print(result);
}
