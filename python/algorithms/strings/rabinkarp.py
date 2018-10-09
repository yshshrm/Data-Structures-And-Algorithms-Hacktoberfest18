# Implementation version of Rabin - Karp algorithm provided in CLRS

d = 256
def search(pat, txt, q): 
    M = len(pat) 
    N = len(txt) 
    i = 0
    j = 0
    p = 0    # hash value for pattern 
    t = 0    # hash value for txt 
    h = 1
  
    # The value of h would be "pow(d, M-1)%q" 
    for i in range(M-1): 
        h = (h*d)%q 

    # Calculate the hash value of pattern and first window 
    # of text 
    for i in range(M): 
        p = (d*p + ord(pat[i]))%q 
        t = (d*t + ord(txt[i]))%q 
    
    for i in range(N-M+1): 
        if p==t: 
            for j in range(M): 
                if txt[i+j] != pat[j]: 
                    break 
            j+=1
            if j==M: 
                print("Pattern found at index " + str(i))
  
        if i < N-M: 
            t = (d*(t-ord(txt[i])*h) + ord(txt[i+M]))%q 
            if t < 0: 
                t = t+q 

search('tr','tring',101)