def min_heapify(a,i):
    l = 2*i+1
    r = 2*i+2
    if l<=(len(a)-1) and a[l] < a[i]:
        largest = l
    else:
        largest = i
    if r<=(len(a)-1) and a[r] < a[largest]:
        largest = r

    if largest!=i:
        temp = a[i]
        a[i] = a[largest]
        a[largest] = temp
        min_heapify(a,largest)

def build_heap(a):
    for i in range((int(len(a)/2-1)),-1,-1):
        min_heapify(a,i)

def get_min(a):
    return a[0]

def extract_min(a):
    root = a[0]
    a[0] = a[len(a)-1]
    a.pop()
    min_heapify(a,0)
    return root


def insert_key(a,k):
    a.append(k)
    print (a)
    i = len(a)-1
    while(a[i] < a[int((i-1)/2)]):
        temp = a[int((i-1)/2)]
        a[int((i-1)/2)] = a[i]
        a[i] = temp
        i = int((i-1)/2)
    return a


print ("give an array : ",end=" ")
a = list(map(int,input().split()))
print (build_heap(a))
