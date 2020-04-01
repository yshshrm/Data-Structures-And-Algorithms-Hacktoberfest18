#this is a python program for left rotation and in this all the input is taken by the user
#here d is the how many rotation you wants and a is the list 
arr = list(map(int,input().split()))
d = int(input())
d = d%len(arr)
temp = arr[d:]
for i in range(d):
    temp.append(arr[i])
print(*temp)
         
