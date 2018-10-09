#this is a program to find the largest prime factor of a number
#here t is the test case and n is the number of input
t = int(input())
while(t):
    t-=1
    n = int(input())
    i=2
    while (i*i<=n):
        if(n%i==0):
            n = int(n/i)
        i+=1
    if(n>2):
        i=n
        print(i)

    
//cool
