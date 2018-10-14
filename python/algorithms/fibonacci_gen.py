from typing import Generator


def fib_gen() -> Generator:
    """ Fibonacce Generator """
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


def get_fib_number(n: int) -> int:
    """
    Get Fibonacci number
    
    >>> get_fib_number(0)
    >>> get_fib_number(1)
    0
    >>> get_fib_number(2)
    1
    >>> get_fib_number(3)
    1
    >>> get_fib_number(4)
    2
    >>> get_fib_number(5)
    3    
    """
    result = None
    fib = fib_gen()  # type: Generator
    
    try:
        for _ in range(n):
            result = next(fib)  # type: int
    except Exception as ex:
        print('-' * 10)
        print(ex)
        print('-' * 10)
        
    return result
