def binary_search(arr,element):
    lower = 0
    upper = len(arr) - 1
    while(lower < upper):
        mid = (lower + (upper - 1)) // 2
        if arr[mid] > element:
            upper = mid-1
        elif arr[mid] < element:
            lower = mid + 1
        else:
            return True
    return False
