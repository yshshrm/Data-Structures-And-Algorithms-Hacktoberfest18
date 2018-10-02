# Implementation of Quick Sort in Python
# Last Edited 10/21/17 (implemented qsort_firstE(arr))
# Worst case performance: O(n^2)
# Average performance: O(nlogn)

# In this first implementation of quick sort, the choice of pivot
# is always the first element in the array, namely arr[0]
def qsort_firstE(arr):
    # if the array is empty, return the empty array
    if not arr: 
        return arr
    # otherwise, partition the array around the pivot, and concatenate 
    # the recursively sorted arrays
    else:
        left = [x for x in arr[1:] if x < arr[0]]
        right = [x for x in arr[1:] if x >= arr[0]]
        return qsort_firstE(left) + [arr[0]] + qsort_firstE(right)

# Test case 1.
#       quicksorting an empty array returns an empty array
print(qsort_firstE([]))
# Test case 2.
#       quicksorting an array with negative, repeating values
print(qsort_firstE([3, 6, 82, 23, -4, -102, 23, -8, 3, 0]))
