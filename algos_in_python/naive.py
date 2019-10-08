text=input("Enter the text : ")
pattern=input("Now, Enter the pattern : ")

def simpleScan(text,pattern):
    count=0
    m=len(pattern)
    match=-1
    j=0
    k=0
    i=j
    while(j<len(text)):
        if(k>=m):
            match=i
            break
        count+=1
        if(pattern[k]==text[j]):
            j+=1
            k+=1

        else:
            backup=k
            j=j-backup
            k=k-backup
            j+=1
            i=j
        
    return match,count

def simpleScanforloop(text,pattern):
    m=len(pattern)
    n=len(text)
    count=0
    match=-1
    for j in range(0,n-m+1):
        i=0

        for i in range (0,m):
            count+=1
            if(pattern[i]!=text[j+i]):
                break
            
            if(i==m-1):
                match=j
                break
        if(match!=-1):
            break
    
    return match,count

print(simpleScan(text,pattern))

print(simpleScanforloop(text, pattern))
        
