def heapify(l,i,n):
    leftChild = 2*i + 1
    rightChild = 2*i + 2
    largest = i
    if(leftChild <= n-1 and l[leftChild] > l[largest]):
        largest = leftChild
    if(rightChild <= n-1 and l[rightChild] > l[largest]):
        largest = rightChild
    if(largest != i):
        l[i],l[largest] = l[largest],l[i]
        heapify(l, largest,n)

def heapSort(l):
    n = len(l)
    for i in range((n//2)-1,-1,-1):
        heapify(l,i,n)
    for i in range(n-1,-1,-1):
        l[0],l[i] = l[i],l[0]
        heapify(l,0,i)
    return l
