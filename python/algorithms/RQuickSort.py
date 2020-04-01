import random
def partition(a, l, r):
    pivot = a[r]
    i = l - 1
    
    for j in range(l, r):
        if a[j] <= pivot:
            i = i + 1
            a[i], a[j] = a[j], a[i]
    a[i+1], a[r] = a[r], a[i+1]
    return i+1



def RQS(a, l, r):
    if (l < r):
        p = random.randint(l, r)
        a[p], a[r] = a[r], a[p]
        k = partition(a, l, r)
        RQS(a, l, k-1)
        RQS(a, k + 1, r)

print "Enter Unsorted array (enclosed in square brackets): "
a = input()
RQS(a, 0, len(a) - 1)
print "Sorted array is:- "
print a
