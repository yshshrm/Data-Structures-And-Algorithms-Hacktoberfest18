def sieve(n):
    prime=[True for i in range(n+1)]

    for i in range(2,(n+1)**0.5):
        if prime[i]==True:
            for num in range(2*i,n+1,i):
                prime[num]=False
        else:
            pass
    for p in range(2,n):
        if prime[p]==True:
            print(p)

