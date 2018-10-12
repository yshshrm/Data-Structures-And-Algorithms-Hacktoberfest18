""" The (Linear) Integer Partition Problem into k equal parts """
l = [7, 3, 2, 1, 5, 4, 8]
k = 3

n = len(l)
mat = [[l[0] for j in range(k)] for i in range(n)]
div = [[0 for i in range(k)] for i in range(n)]

def partition(n, k, li):
    if (k>0) :
        print(l[div[n][k]+1:li])
        partition(div[n][k], k-1, div[n][k]+1)
    else:
        print(l[0:n+1])

for i in range(n):
    mat[i][0] = sum(l[:i+1])

for i in range(1, k):
    for j in range(1, n):
        x = list()
        for m in range(0,j):
            x.append(max(mat[m][i-1], sum(l[m+1:j+1])))
        x.append(mat[j][i-1])
        mat[j][i] = min(x)
        div[j][i] = x.index(min(x))

print("Partitions : ")
partition(n-1, k-1, n)