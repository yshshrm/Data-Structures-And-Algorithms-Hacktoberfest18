from math import sqrt, floor

def Sieve(n):
    num = math.floor(math.sqrt(n))
    A = [True]*(n+1)
    A[0] = False
    A[1] = False
    for i in range(2, num+1):
        if A[i] == True:
            for j in range(i*i, n+1, i):
                A[j] = False
    res = []
    for i in range(n+1):
        if(A[i]) == True:
            res.append(i)
    return(res)
