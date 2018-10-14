v = []
for i in range(5):
    vi = [False,False,False,False,False]
    v.append(vi)
def imp(a,p,q):
    if(p >= 0 and p < 5 and q >= 0 and q < 5 ):
        # print(p,q,end = " ")
        if(a[p][q] == 1):
            if(v[p][q] == False):
                return 1
    return 0

def dfs(a,x,y):
    v[x][y] = True
    if(imp(a,x,y+1)):
        dfs(a,x,y+1)
    if(imp(a,x+1,y)):
        dfs(a,x+1,y)
    if(imp(a,x-1,y)):
        dfs(a,x-1,y)
    if(imp(a,x,y-1)):
        imp(a,x,y-1)

def no_of_islands(a):
    counter = 0
    for i in range(5):
        for j in range(5):
            if(imp(a,i,j)):
                dfs(a,i,j)
                v[i][j] = True
                counter += 1
    return counter

a = []
for i in range(5):
    b = list(map(int,input().strip().split(" ")))
    a.append(b)
c = no_of_islands(a)
print(c)
