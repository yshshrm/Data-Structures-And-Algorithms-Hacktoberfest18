"""
Program: prints N(input) Ramanujan numbers
Programmer: Rudra
ID: https://github.com/dynamite-bud
"""

cubert=lambda x: pow(x,1.0/3.0)

N = int(input("How many ramanujan numbers do you want: "))
def printRamanujan(N):
    count=0
    i=1
    while (count < N):
        checker = 0
        for j in range(1,int(cubert(i))+1):
            for k in range(j+1,int(cubert(i))+1):
                if (j*j*j + k*k*k == i):
                    checker+=1
        if checker == 2:
            count += 1
            print(count," ",i)
        i+=1


printRamanujan(N)



"""also the taaxicab number
"""
