""" Knapsack problem by dynamic programming """
weight = [1,3,4,5]
value = [1,4,5,7]
n = len(weight)+1
max_wt = 7
v = [[0 for j in range(max_wt+1)] for i in range(n)]

def print_items(i, j):
    if i>0 and j>0 :
        if v[i][j] != v[i-1][j] :
            print(str(weight[i-1])+"\t\t\t"+str(value[i-1]))
            print_items(i-1, v[i-1].index(v[i][j]-value[i-1]))
        else :
            print_items(i-1, j)
        

def knapsack():
    for i in range(1, n):
        for j in range(1, max_wt+1):
            if j-weight[i-1] >= 0 :
                v[i][j] = max([v[i-1][j], v[i-1][j-weight[i-1]]+value[i-1]])
            else :
                v[i][j] = v[i-1][j]
    print("Selected Weight\t\tValue")
    print_items(n-1, max_wt)
    print("\nMaximum Value : "+str(v[n-1][max_wt]))

knapsack()