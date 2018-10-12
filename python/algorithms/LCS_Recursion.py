""" Longest Common Subsequence using recursion """
str1 = input("Enter the string : ")
str2 = input("Enter the string to compare : ")
n = len(str1)
m = len(str2)

def check(i, j):
    if str1[i] == str2[j]:
        return True
    else:
        return False

def lcs(i, j):
    if i == n or j == m :
        return 0
    elif check(i, j):
        return 1+lcs(i+1, j+1)
    else :
        return max(lcs(i+1, j), lcs(i, j+1))

print("Length of Longest Increasing Subsequence : "+str(lcs(0, 0)))