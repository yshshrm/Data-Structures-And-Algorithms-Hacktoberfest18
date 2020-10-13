# IMPLEMENTATION OF SIEVE OF ERATOSTHENES TO FIND PRIME NUMBERS BEFORE A NUMBER N
# IN PYTHON 3

def sieveEratosthenes(n):
    prime = [True for i in range(n+1)]              #make a bool array of size n 
    p = 2 
    while(p*p <= n):
        if prime[p]==True:                          
            for i in range(p*p,n+1,p):              #append by p to eliminate all multiples of p
                prime[i]=False                      
                
        p+=1
    
    for p in range(2,n):
        if prime[p]:                                #if prime[p] is not false
            print(p)
            

n = int(input())
print(sieveEratosthenes(n))