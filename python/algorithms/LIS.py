""" Longest Incresing Subsequence """
arr = [3,4,-1,0,2,3]
n = len(arr)

lis = [1 for i in range(n)]
lis_list = [[arr[i]] for i in range(n)]

for i in range(1,n):
    for j in range(0,i):
        if(arr[j]<=arr[i]):
            lis[i] = max(lis[i], lis[j]+1)
            lis_list[j].append(arr[i])

max_len = max(lis)
print("Length of Longest Incresing Subsequence : " + str(max_len))
for seq in lis_list:
    if len(seq) == max_len:
        print(seq)