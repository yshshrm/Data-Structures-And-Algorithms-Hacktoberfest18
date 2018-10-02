# python program to search for a number linearlly in a list

def LinearSearch(l,val):
    for i in range(len(l)):
        if (l[i]==val):
            return i
    return -1

prompt = "enter a list of numbers seperated by spaces:"
l=list(map(int, input(prompt).split()))

val=int(input("enter the number to be searched:"))

i= LinearSearch(l,val)
if(i==-1):
    print("%d not found"%val)
else:
    print("%d found at position %d"%(val,i))

            
