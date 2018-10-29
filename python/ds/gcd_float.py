#this is a simple program where you can calculate the gcd of float numbers
import math 
def gcd(a,b) : 
    if (a < b) : 
        return gcd(b, a) 
    if (abs(b) < 0.001) : 
        return a 
    else : 
        return (gcd(b, a - math.floor(a / b) * b)) 
 
a = float(input())
b = float(input())
print('{0:.1f}'.format(gcd(a, b))) 
  
