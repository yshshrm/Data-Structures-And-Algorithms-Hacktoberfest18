//KMP algorith

//failure Fucntion--> to find the failure values where the pattern dosent match
f[0]=-1
j=1
i=f[0]
        if p[j]==p[j+1]     //p is the patter array
            f[j]=i+1
            j=j+1
            i=i+1
        else if i>=0 then 
                i=f[i-1]
            else
                f[j]=-1 ("match not found")
                j=j+1
//KMP function TO find the patter in the given string

i=0
j=0
    while i<n 
        if t[i]==p[i]     // t is the main string to search the pattern in 
            if j=m-1      // m is the length of pattern string
                return i-j ("pattern Found")       // return the position where the pattern is found
            else 
                i=i+1
                j=j+1
        else 
            if j>0
                j=f[j-1]+1
                else
                    i=i+1
                    return -1 ["pattern not found"]
