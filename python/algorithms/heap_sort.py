def heapify(arr, n, i): 
    '''
        takes array: arr, size of heap: n, index: i
    '''
    root = i 
    left = 2*i+1     
    right = 2*i+2     
  
    if left < n and arr[root] < arr[left]: 
        root = left 
  
    if right < n and arr[root] < arr[right]: 
        root = right 

    if root != i: 
        arr[i],arr[root] = arr[root],arr[i] 
        heapify(arr, n, root) 
  
def heapSort(arr): 
    n = len(arr) 
  
    for i in range(n, -1, -1): 
        heapify(arr, n, i) 
  
    for i in range(n-1, 0, -1): 
        arr[i], arr[0] = arr[0], arr[i] 
        heapify(arr, i, 0) 
  
 