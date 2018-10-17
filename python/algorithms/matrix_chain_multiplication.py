""" Matrix Chain Multiplication """
dim = [2,3,4,1,5,2]

n = len(dim)-1
mul = [[0 for j in range(n)] for i in range(n)]
p = [[0 for j in range(n)] for i in range(n)]

for i in range(0,n-1):
    for j in range(0, n-1-i):
        x = list()
        for k in range(j, j+i+1):
            print(j, k, j+i+1)
            x.append(mul[j][k]+mul[k+1][j+i+1]+dim[j]*dim[k+1]*dim[j+i+1+1])
        mul[j][j+i+1] = min(x)
        p[j][j+i+1] = j+x.index(min(x))+1

print(mul)
print(p)