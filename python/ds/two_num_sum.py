arr=list()
n=int(input("enter the no. of elements "))
for i in range(0,n):
    arr.append(int(input("num: ")))
sum =int(input("enter the sum of two numbers "))
sorted(arr)
l=0
h=n-1
c=0
while(l<h):
    if(arr[l]+arr[h]==sum):
        print("two numbers whose sum matches the given sum are",arr[l],arr[h])
        c=1
        break
    elif(arr[l]+arr[h]<sum):
        l=l+1
    else:
        h=h-1
if(c==0):
    print("no matches found")
