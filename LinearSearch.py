# Python program for the execution of linear search algorithm    
# The function will loop over every element and return the index if it matches.    
# Otherwise, it will return -1    
    
# Defining the function    
def linear_search(array, x):    
        
    # looping over every element    
    for i in range(len(array)):    
        # Comparing the element    
        if array[i] == x:    
            return i    
    # If not found, any index returning -1    
    return -1    
    
    
    
# Implementing the code    
array = [5, 8, 16, 37, 59, 80]  
print(f"Array = {array}")   
    
# Case - 1:- Element is present in the list    
x = 59    
    
# Calling the function    
index = linear_search(array, x)    
    
if index != -1:    
    print(f"The given element {x} is present at the index", str(index))    
else:    
    print(f"The given element {x} is not present in the array")    
        
# Case - 2:- Element is not present in the array    
x = 35    
    
# Calling the function    
index = linear_search(array, x)    
    
if index != -1:    
    print(f"The given element {x} is present at the index", str(index))    
else:    
    print(f"The given element {x} is not present in the array")  
