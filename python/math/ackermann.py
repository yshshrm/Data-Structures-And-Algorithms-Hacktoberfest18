# Implemented by itsjustmustafa

#The Ackermann function
#Source: https://en.wikipedia.org/wiki/Ackermann_function

def ackermann(m, n):
    if(m==0):
        return(n+1)
    if(n==0):
        return(ackermann(m-1, 1))
    return(ackermann(m-1, ackermann(m, n-1)))
