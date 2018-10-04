#this is a python program for left rotation and in this all the input is taken by the user
#here n is the  number of input ,d is the how many rotation you wants and a is the list 
n ,d = map(int,input().split())
a = list(map(int,input().split()))
d %=n
a =a[d:]+ a[:d]
print(*a)
         
