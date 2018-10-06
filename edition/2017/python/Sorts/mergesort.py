def mergesort(array):
    #Base case
    if len(array) <= 1:
        return array
    else:
        #Divide the array in half
        mid = round(len(array) / 2)
        left = array[0:mid]
        right = array[mid:]

        #Sort each half of the array
        left = mergesort(left)
        right = mergesort(right)

        #Combine sorted halves
        return merge(left, right)

#Combine two sorted arrays, into one, keeping all the elements in sorted order
def merge(left, right):
    array = list()
    while len(left) > 0 and len(right) > 0:
        #Look at the first element of the left and right arrays
        #And add the smaller one to the output array
        if left[0] < right[0]:
            array.append(left[0])
            del left[0]
        else:
            array.append(right[0])
            del right[0]
    #When the loop ends either left or right will have element(s) left in it
    if len(left) > 0:
        return array + left
    if len(right) > 0:
        return array + right

