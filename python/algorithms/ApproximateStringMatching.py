""" approximate string matching and edit distance """
str1 = input("Enter the string : ")
str2 = input("Enter the string to form : ")

n = len(str1)+1
m = len(str2)+1
arr = [[j for j in range(m)] for i in range(n)]
for i in range(n):
    arr[i][0] = i

def check(i,j):
    if(str1[i] == str2[j]):
        return 1
    else:
        return 0

for i in range(1,n):
    for j in range(1,m):
        arr[i][j] = min([arr[i][j-1]+1, arr[i-1][j]+1, arr[i-1][j-1]+check(i-1,j-1)])
   
print("Edit Distance : "+str(arr[n-1][m-1]))