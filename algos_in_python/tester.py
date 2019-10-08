from merge import *
from quick import *
from heapsort import *
import sys
sys.setrecursionlimit(1500)


array = [7,8,4,5,6,9,7,1,5,8] 
n = len(array) 
print ("Given array is") 
for i in range(n-1): 
    print ("%d" %array[i]), 
  
heapSort(array) 
print ("\n\nSorted array is") 
for i in range(n): 
    print ("%d" %array[i]), 

#print(comparison)
