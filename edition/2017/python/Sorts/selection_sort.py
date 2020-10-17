def selectionSort(lst):
    
    
    for j in range(len(lst)):
        min=lst[j];index=j
        for i in range(j,len(lst)):
            if min>lst[i]:
                index=i
                min=lst[i]
        
        (lst[index],lst[j])=(lst[j],min)
    print(lst)
            



selectionSort([0,5,8,9,56,3,1,5])
