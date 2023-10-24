# Python program for the execution of binary search algorithm  
# The function will return the index of the element if it is present,  
# Otherwise, it will return -1  
  
# Defining the function  
def binary_search(array, x):  
    lower = 0  
    higher = len(array) - 1  
    middle = 0  
  
    while lower <= higher:  
  
        middle = (higher + lower) // 2  
  
        # If x is greater than the middle element, ignoring the left half  
        if array[middle] < x:  
            lower = middle + 1  
  
        # If x is smaller than the middle element, ignoring the right half  
        elif array[middle] > x:  
            higher = middle - 1  
  
        # This means x is present in the middle  
        else:  
            return middle  
  
    # If the loop ends without returning, then the element is not present in the list  
    return -1  
  
  
# Implementing the code  
array = [5, 8, 16, 37, 59, 80]  
  
# Case - 1:- Element is present in the list  
x = 59  
  
# Calling the function  
index = binary_search(array, x)  
print(f"Array = {array}")  
  
if index != -1:  
    print(f"The given element {x} is present at the index", str(index))  
else:  
    print(f"The given element {x} is not present in the array")  
      
# Case - 2:- Element is not present in the array  
x = 35  
  
# Calling the function  
index = binary_search(array, x)  
  
if index != -1:  
    print(f"The given element {x} is present at the index", str(index))  
else:  
    print(f"The given element {x} is not present in the array")  
