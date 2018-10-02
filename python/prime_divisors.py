# Python Program to find the number of prime divisors of a number n

prime_divisors=[0]*1000001
for i in range(2,1000001):
    if(prime_divisors[i]==0):
        prime_divisors[i]=1
        for j in range(i+i,1000001,i):
            prime_divisors[j]+=1

print("Enter n: ")
n=int(input())
print(n,"has",prime_divisors[n],"prime divisor(s)")
