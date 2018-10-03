def gcd(x,y):
    if(x!=0):
        r=y%x
        y=x
        x=r
        i=gcd(x,y)
        return i
    else:
        i=y
        return i
print "enter two values:"
x=input("x=")
y=input("y=")
if(x<y):
    print "the gcd of ",x," and ",y," is ",gcd(x,y)
else:
    print "the gcd of ",x," and ",y," is ",gcd(y,x)

