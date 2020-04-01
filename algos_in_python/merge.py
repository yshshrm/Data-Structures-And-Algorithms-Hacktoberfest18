import sys
sys.setrecursionlimit(1500)

# Python program for implementation of MergeSort 
def mergeSort(arr): 
        comparison=0

        if len(arr) >1: 
                mid = len(arr)//2 #Finding the mid of the array 
                L = arr[:mid] # Dividing the array elements 
                R = arr[mid:] # into 2 halves 

                comparison+=mergeSort(L) # Sorting the first half 
                comparison+=mergeSort(R) # Sorting the second half 

                i = j = k = 0
                
                # Copy data to temp arrays L[] and R[] 
                while i < len(L) and j < len(R): 
                        if L[i] < R[j]: 
                                arr[k] = L[i] 
                                i+=1
                        else: 
                                arr[k] = R[j] 
                                j+=1
                        k+=1
                        comparison+=1
                
                # Checking if any element was left 
                while i < len(L): 
                        arr[k] = L[i] 
                        i+=1
                        k+=1
                        comparison+=1
                
                while j < len(R): 
                        arr[k] = R[j] 
                        j+=1
                        k+=1
                        comparison+=1

        return comparison
