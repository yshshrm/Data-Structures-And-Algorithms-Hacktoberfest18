def insertion_sort(num):

    # We start from 1 since the first element is trivially sorted
    for index in range(1, len(num)):
        currentValue = num[index]
        currentPosition = index

        # As long as we haven't reached the beginning and there is an element
        # in our sorted array larger than the one we're trying to insert - move
        # that element to the right
        while currentPosition > 0 and num[currentPosition - 1] > currentValue:
            num[currentPosition] = num[currentPosition - 1]
            currentPosition = currentPosition - 1

        # We have either reached the beginning of the array or we have found
        # an element of the sorted array that is smaller than the element
        # we're trying to insert at index currentPosition - 1.
        # Either way - we insert the element at currentPosition
        num[currentPosition] = currentValue


num = [4, 22, 41, 40, 27, 30, 36, 16, 42,
       37, 14, 39, 3, 6, 34, 9, 21, 2, 29, 47]

insertion_sort(num)
print("sorted array: " + str(num))
