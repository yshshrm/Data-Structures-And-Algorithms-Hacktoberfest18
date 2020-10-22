n = int(input())
arr = list(map(int,input().split()))

maxx = arr[0]
test = arr[0]

for i in range(1,n):
    test += arr[i]
    if test < arr[i]:
        test = arr[i]
    maxx = max(test, maxx)

print(maxx)


