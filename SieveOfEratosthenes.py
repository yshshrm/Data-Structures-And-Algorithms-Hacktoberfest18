import math
def sieve(n):
    isprime[0] = isprime[1] = False
    for i in range(2, math.sqrt(n) + 1):
        if isprime[i]:
            primes.append(i)
            for j in range(i*i, n+1, i):
                isprime[j] = False

n = int(input())
isprime = [True for i in range(n+1)]
primes = []

print('The prime numbers from 1 to', n, 'are:')
print(*primes)