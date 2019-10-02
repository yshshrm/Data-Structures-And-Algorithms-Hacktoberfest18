# python program to construct MaxHeap data structure

# heapify to restore the property of heaps 
def Heapify(arr, n, i):
    largest = i
    l = 2 * i + 1 
    r = 2 * i + 2 
    if l < n and arr[l] > arr[largest]:
        largest = l 
    if r < n and arr[r] > arr[largest]:
        largest = r 
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        Heapify(arr, n, largest)
        
# building the heap from array        
def BuildHeap(arr):
    n = len(arr)
    for i in range(n // 2, -1, -1):
        Heapify(arr, n, i)

# getting maximum element from heap 
def GetMaxHeap(arr):
    return arr[0]

# sorting heap 
def HeapSort(arr):
    BuildHeap(arr)
    n = len(arr)
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        Heapify(arr, i, 0)

# getting parent 
def Parent(i):
    return i // 2 - 1
    
# inserting element in heap     
def HeapInsert(arr, x):
    arr.append(x)
    n = len(arr)
    i = n - 1
    print(Parent(i))
    while(i > 1 and arr[Parent(i)] < x): 
        arr[i], arr[Parent(i)] = arr[Parent(i)], arr[i]
        i = Parent(i)

# extracting the maximum element 
def ExtractMax(arr):
    n = len(arr)
    arr[0], arr[n-1] = arr[n-1], arr[0]
    arr.pop()
    Heapify(arr, n-1, 0)
    
arr = [ 12, 11, 13, 5, 6, 7] 
BuildHeap(arr) 
print(arr)  # output : [13, 11, 12, 5, 6, 7]
HeapSort(arr) 
print(arr)  # output : [5, 6, 7, 11, 12, 13]