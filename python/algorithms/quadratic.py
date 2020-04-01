'''
Program to solve quadratic equation
'''
import math
print('Enter a,b,c in ax^2+bx+c=0')
a,b,c=map(int,input().strip().split(' '))
if a==0:
    print('a has to be non zero')
else:
    d=b**2-(4*a*c)
    if d<0:
        print('No real roots')
    elif d==0:
        print('Equal roots')
        root=-b/(2*a)
        print('Root',root)
    else:
        print(d)
        print('Unequal roots')
        root1=(-b+math.sqrt(d))/(2*a)
        root2=(-b-math.sqrt(d))/(2*a)
        print('Roots x1=',root1,'x2=',root2)
