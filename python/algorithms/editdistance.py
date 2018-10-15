# import sys
import numpy

def editDistance(t, s):
    if t == s: return 0
    n = len(t)
    m = len(s)
    distMat = numpy.zeros((m+1, n+1))
    distMat[0] = range(n+1)
    distMat[:,0] = range(m+1)
    for i in range(1,n+1):
        for j in range(1,m+1):
            subCost = 1 if t[i-1] != s[j-1] else 0
            distMat[j, i] = min(distMat[j, i-1] + 1, distMat[j-1, i-1] + subCost, distMat[j-1, i] + 1)
    return distMat[m,n]

