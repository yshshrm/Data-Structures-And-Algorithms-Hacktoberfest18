""" longest common subsequence """
str1 = input("Enter the string : ")
str2 = input("Enter the string to compare : ")
n = len(str1)+1
m = len(str2)+1

arr = [[0 for j in range(m)] for i in range(n)]

def check(i, j):
    if str1[i] == str2[j] :
        return 1
    else:
        return 0

for i in range(1,n):
    for j in range(1,m):
        if check(i-1,j-1):
            arr[i][j] = arr[i-1][j-1]+1
            lcs += str1[i-1]
        else:
            arr[i][j] = max([arr[i-1][j], arr[i][j-1]])

lcs = ""
i,j = n-1,m-1
while (i!=0 or j!=0):
    if arr[i][j]==arr[i-1][j-1]+1:
        lcs = str1[i-1] + lcs
        i -= 1
        j -= 1
    elif arr[i][j] == arr[i-1][j]:
        i -= 1
    else:
        j -= 1

print("Longest Common Subsequence : "+lcs)
print("Length of Longest Increasing Subsequence : "+str(arr[n-1][m-1]))