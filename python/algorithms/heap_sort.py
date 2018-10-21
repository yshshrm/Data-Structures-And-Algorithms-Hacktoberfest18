import math

def parent (i):
    return math.floor(i/2)

def right (i):
    return 2 * i

def left (i):
    return 2*i + 1

def max_heapify (A, i, heap_size):
    l = left(i)
    r = right(i)
    
    if (l <= heap_size and A[l] > A[i]):
        largest = l;
    else:
        largest = i;
    
    if (r <= heap_size and A[r] > A[largest]):
        largest = r
        
    if (largest != i):
        A[i],A[largest] = A[largest],A[i]
        max_heapify(A, largest, heap_size)
        
        
        
def build_max_heap (A):
    heap_size = len(A) - 1
    
    for i in range(math.floor((len(A)-1)/2) , -1 , -1):
        max_heapify(A, i, heap_size)
        
    return heap_size
       
        
def heap_sort (A):
    heap_size = build_max_heap(A)
    for i in range(len(A) - 1, 0, -1):
        A[i],A[0] = A[0], A[i]
        heap_size = heap_size - 1;
        max_heapify(A, 0, heap_size)


A = [9,8,7,6,5,4,3,2,1]
print("Before Sorting")
print(A)  
heap_sort(A)
print("After Sorting")      
print(A)
        
        