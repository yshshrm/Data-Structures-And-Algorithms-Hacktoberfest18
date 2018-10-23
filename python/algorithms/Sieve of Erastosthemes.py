import math
print "---Sieve of Erastosthenes!!---"
print "To find wether inputed number is prime"

print "Enter a number"		
n=int(raw_input())
m=int(math.sqrt(n))
flag=1					            #assume n is prime
prime = [1]*n
for i in xrange(1,int(math.sqrt(n))):
	prime[i] = 1  #all are prime
i=2
while (i <= m):
	if(prime[i] == 1):  
		if(n % i == 0):
			flag=0			          #'n' is not prime
			break
		else:			              #croosing-out multiples of 'i'
			j=2*i
			while(j < m):
				prime[j]=0
				j=j+i
	i=i+1
if(flag == 0):
	print str(n) +" is not a prime number"
else:
	print str(n) + " is a prime number"
