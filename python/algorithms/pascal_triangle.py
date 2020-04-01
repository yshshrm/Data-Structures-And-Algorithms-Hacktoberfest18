import numpy as np
##This function returns a numpy array which represents the Pascal Triangle of (n+1) lines

def triangle(n):
    T = np.zeros((n+1,n+1))
    for i in range(n+1):
        T[i,0],T[i,i] = 1,1
    for i in range(2,n+1):
        for j in range(1,i):
            T[i,j] = T[i-1,j] + T[i-1,j-1]
    return(T)
