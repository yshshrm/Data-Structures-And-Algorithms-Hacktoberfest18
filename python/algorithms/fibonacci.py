# n-th Fibonacci number (linear time)

def fib(n):
  a = 1
  b = 1
  
  for _ in range(0,n-2):
    a, b = b, a+b
    
  return b
