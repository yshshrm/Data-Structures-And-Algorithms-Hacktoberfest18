""" computing binomial coefficient """
n = int(input("Enter the degree : "))

b = [[1 for j in range(i+1)] for i in range(n+1)]
for i in range(2,n+1):
    for j in range(1,i):
        b[i][j] = b[i-1][j] + b[i-1][j-1]

print(b)