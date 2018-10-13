# n-th Fibonacci number (linear time)

def fib(n):
  a = 1
  b = 1
  
  #Printing The Series
  for j in range(0,n):
    c=a+b
    print a+";"
    a=b
    b=c
