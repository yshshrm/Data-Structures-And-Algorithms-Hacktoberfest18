# In mathematics, a Thabit Number is a positive integer of the form 3* 2n – 1, where n is a non negative integer.
#Approach
#Add 1 to the given number, Now the number must be of the form 3*2n
#Divide the number by 3, By now the number must be of the form 2n
#Check if the number is a power of 2 or not, To check if the number is power of two or not
#If the number is power of 2 then Print ‘YES’ otherwise ‘NO’.

def isPowerOfTwo(n):  
        
    return (n and (not(n & (n - 1))))  
def isThabitNumber( n ): 

    n = n + 1; 

    if (n % 3 == 0): 
        n = n//3; 
    else: 
       return False
 
    if (isPowerOfTwo(n)): 
        return True
       
    else: 
         return False    
  
n = int(input())
if (isThabitNumber(n)): 
    print("YES") 
else:   
    print("NO")  
