def shellSort(items,k):
    if k==0:
        k=2
    inc = len(items) // k
    while inc:
        for i in range(len(items)):
            j = i
            temp = items[i]
            while j >= inc and items[j-inc] > temp:
                items[j] = items[j - inc]
                j -= inc
            items[j] = temp
        inc = inc//k if inc//k else (0 if inc==1 else 1)
    print(items)
        

shellSort([234,5,67,8,-2,4,67,8,90,90,0,5],8)

    
