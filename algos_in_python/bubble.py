def bubblesort(array):
    comparison=0;
    for i in range(len(array)):
        
        for j in range(len(array)-i-1):
            comparison+=1
            if(array[j]>array[j+1]):
                array[j],array[j+1]=array[j+1],array[j]
               
       

    return comparison
