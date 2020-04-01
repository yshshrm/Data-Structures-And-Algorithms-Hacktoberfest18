a = [16, 19, 11, 15, 10, 12, 14]

i = 0
while i<len(a):
    #smallest element in the sublist
    smallest = min(a[i:])
    #index of smallest element
    index_of_smallest = a.index(smallest)
    #swapping
    a[i],a[index_of_smallest] = a[index_of_smallest],a[i]
    i=i+1
print (a)
