#this is a mathematical algorithm which is called interprime
#In Mathematics, An interprime is a positive integer representing average of two consecutive odd prime numbers

def isPrime(n) :    

    if (n <= 1) :    
        return False
    if (n <= 3) :    
        return True
    if (n % 2 == 0 or n % 3 == 0) :    
        return False
      
    i = 5
    while (i * i <= n) :    
        if (n % i == 0 or n % (i + 2) == 0) :    
            return False
        i = i + 6
      
    return True

def isInterprime( n): 

       
     if (n < 4): 
        return False
       
       
     prev_prime = n 
     next_prime = n 

     while (isPrime(prev_prime)== 0): 
         prev_prime = prev_prime-1
 
     while (isPrime(next_prime)== 0): 
         next_prime = next_prime + 1
     if ((prev_prime + next_prime)== 2 * n): 
         return True
     else: 
        return False    
          
n = int(input())
if(isInterprime(n)): 
    print("YES") 
else: 
    print("NO") 
