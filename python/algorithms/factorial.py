def factorialNum(number):
    """Python program to find the factorial of a number provided by the user.

    Args:
        number (Int): Input an integer 

    Returns:
        Int: Return a number which is a factorial of the input
    """    
    factorial = 1 
    if number < 0:
        print("Factorial does not exist for negative numbers")
    elif number == 0 or number == 1:
        return 1
    else:
        for i in range(1,number+1):
            factorial = factorial*i
        return factorial

print(factorialNum(7))
