def selectionsort(array):
    comparison=0
    for i in range(0,len(array)-1):
        minimum=array[i]
        position=i
        for j in range(i+1,len(array)):
            comparison+=1
            if(array[j]<minimum):
                minimum=array[j]
                position=j
        array[position]=array[i]
        array[i]=minimum
       
    return comparison
