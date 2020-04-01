def sieve_of_eratosthenes(n):
    l=[]
    l1=[]
    for i in range(2,n+1):
        l.append(i)
        l1.append(1)
    for i in range(2,n+1):
        for j in range(len(l1)):
            if l[j]%i==0 and l[j]!=i:
                l1[j]=0
    for i in range(len(l1)):
        if l1[i]==1:
            print(l[i])
sieve_of_eratosthenes(10)
