def shellSort(items):
    inc = len(items) / 2
    while inc:
        for i in xrange(len(items)):
            j = i
            temp = items[i]
            while j >= inc and items[j-inc] > temp:
                items[j] = items[j - inc]
                j -= inc
            items[j] = temp
        inc = inc/2 if inc/2 else (0 if inc==1 else 1)

a = [35, -8, 11, 1, 68, 0, 3];
shellSort(a)
print a # [-8, 0, 1, 3, 11, 35, 68]
