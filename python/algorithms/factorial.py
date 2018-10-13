def factorial(num):
    if num==1:
        return (1)
    else:
        return (num*factorial(num-1))
number=input("what number do you want the factorical of?")
print ('the factorical of {0} is {1}'.format(number,factorial(number)))
