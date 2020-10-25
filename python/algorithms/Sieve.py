prime = [0]*1000001
    
def sieve():
    for i in range(3, 1000001, 2):
        prime[i] = 1
    for i in range(3, 1000001, 2):
        if prime[i] == 1:
            for j in range(i*i, 1000001, i):
                prime[j] = 0

    prime[2] = 1

sieve()
