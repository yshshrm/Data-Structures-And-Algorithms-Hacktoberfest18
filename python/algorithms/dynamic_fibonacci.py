def fibonacci_sequance(n): 
    
    FibArray = [0, 1] 
      
    while len(FibArray) < n + 1:  
        FibArray.append(0)  
      
    if n <= 1: 
       return n 
    else: 
       if FibArray[n - 1] ==  0: 
           FibArray[n - 1] = fibonacci_sequance(n - 1) 
      
       if FibArray[n - 2] ==  0: 
           FibArray[n - 2] = fibonacci_sequance(n - 2) 
      
       FibArray[n] = FibArray[n - 2] + FibArray[n - 1] 
    return FibArray[n] 
      
i = int(input("enter a number"))
print(fibonacci_sequance(i))