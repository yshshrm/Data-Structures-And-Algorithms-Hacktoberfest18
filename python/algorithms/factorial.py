def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)


def main():
    print("Enter a number: ")
    result = factorial(int(input()))
    print("Result: " + str(result))

if __name__ == '__main__':
    main()