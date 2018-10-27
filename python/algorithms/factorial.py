'''
Program to find factorial of a number
'''
def factorial(n):
    if n==0:
        return 1
    else:
        return n*factorial(n-1)
print('Enter a number')
n=int(input())
print('Factorial of',n,'is',factorial(n))
