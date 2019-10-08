text=input("Enter the text : ")
pattern=input("Now, Enter the pattern : ")


#using while loop 
def computeFail(pattern):
    m=len(pattern)

    k=0
    s=0 
    fail_count=0
    fail=[0]*m

    fail[0]=-1
    for k in range(1,m):
        s=fail[k-1]
        while(s>=0):
            fail_count+=1
            if(pattern[s]==pattern[k-1]):
                break
            s=fail[s]
        fail[k]=s+1
    return fail,fail_count

# this is second function doing the same thing but only diff using while loop
def scan(pattern,text):
    match=-1
    m=len(pattern)
    j=0
    k=0
    count=0
    fail,fail_count=computeFail(pattern)
    while(j<len(text)):
        count+=1
        if(k==m):
            match=j-m
            break
        
        if(k==-1):
            k=0
            j+=1

        if(pattern[k]==text[j]):
            k+=1
            j+=1

        else:
            k=fail[k]
    
    return match,count,fail_count


match,count,fail_count=scan(pattern,text)
print(match,count,fail_count)