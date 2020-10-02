def heapsorting(arr, n, i):
   largest = i # largest value
   l = 2 * i + 1 # left
   r = 2 * i + 2 # right

   if l < n and arr[i] < arr[l]:
      largest = l

   if r < n and arr[largest] < arr[r]:
      largest = r

   if largest != i:
      arr[i],arr[largest] = arr[largest],arr[i] # swap
      # root.
      heapsorting(arr, n, largest)

def heapSort(arr):
   n = len(arr)
   
   for i in range(n, -1, -1):
      heapsorting(arr, n, i)

   for i in range(n-1, 0, -1):
      arr[i], arr[0] = arr[0], arr[i] # swap
      heapsorting(arr, i, 0)

arr = [2,5,3,8,6,5,4,7]
heapSort(arr)
n = len(arr)
print ("Sorted array is")
for i in range(n):
   print (arr[i],end=" ")
