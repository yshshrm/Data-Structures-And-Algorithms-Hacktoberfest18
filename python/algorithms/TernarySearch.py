def ternary_search(A, l, r, val):
    if r >= l:
        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3

        if A[mid1] == val:
            return mid1

        if A[mid2] == val:
            return mid2

        if val < A[mid1]:
            return ternary_search(A, l, mid1 - 1, val)
        
        elif val > A[mid2]:
            return ternary_search(A, mid2 + 1, r, val)

        else:
            return ternary_search(A, mid1 + 1, mid2 - 1, val)

    return -1

A = list(map(int, input().split()))
val = int(input())

idx = ternary_search(A, 0, len(A) - 1, val)

if idx == -1:
    print('Element not found!')
else: 
    print('Element found at index', idx)

