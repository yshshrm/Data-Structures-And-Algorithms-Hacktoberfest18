def mergeSort(alist):
    if len(alist) > 1:
        mid = len(alist)//2
        leftSide = alist[:mid]
        rightSide = alist[mid:]

        mergeSort(leftSide)
        mergeSort(rightSide)

        i=j=k = 0
        while i < len(leftSide) and j < len(rightSide):
            if leftSide[i] < rightSide[j]:
                alist[k] = leftSide[i]
                i = i+1
            else:
                alist[k] = rightSide[j]
                j = j+1
            k = k+1

        while i < len(leftSide):
            alist[k] = leftSide[i]
            i = i+1
            k = k+1

        while j < len(rightSide):
            alist[k] = rightSide[j]
            j = j+1
            k = k+1
