# Python program for the execution of insertion sort algorithm  
  
# Defining the function  
def insertion_sort(array):  
  
    # Traversing through 1 to the length of the array  
    for i in range(1, len(array)):  
  
        key = array[i]  
  
        # Moving elements of array[0..i-1], that are  
        # bigger than the key, to one index ahead  
        # of their current index  
        c = i-1  
        while c >= 0 and key < array[c]:  
            array[c + 1] = array[c]  
            c -= 1  
  
        array[c + 1] = key  
  
# Sorting the array using insertion_sort  
array = [23, 42, 3, 83, 36, 49, 19]  
print("Unsorted array:", array)  
  
# Calling the function  
insertion_sort(array)  
print("Sorted array:", array)  
