
# Fibonacci Series using Dynamic Programming 
def fibonacci(n): 
      
    # Taking 1st two fibonacci nubers as 0 and 1 
    fibonacciArray = [0, 1] 
      
    while len(fibonacciArray) < n + 1:  
        fibonacciArray.append(0)  
      
    if n <= 1: 
       return n 
    else: 
       if fibonacciArray[n - 1] ==  0: 
           fibonacciArray[n - 1] = fibonacci(n - 1) 
      
       if fibonacciArray[n - 2] ==  0: 
           fibonacciArray[n - 2] = fibonacci(n - 2) 
      
       fibonacciArray[n] = fibonacciArray[n - 2] + fibonacciArray[n - 1] 
    return fibonacciArray[n] 
      
print(fibonacci(9)) 