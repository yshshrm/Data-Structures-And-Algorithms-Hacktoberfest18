import functools
from time import clock
#import sys
#sys.setrecursionlimit()

@functools.lru_cache(None)
def fib_lru(n):
    if n < 2:
        return n
    return fib_lru(n-1) + fib_lru(n-2)

def fib_memo(n, computed = {0: 0, 1: 1}):
    if n not in computed:
        computed[n] = fib_memo(n-1, computed) + fib_memo(n-2, computed)
    return computed[n]

def fib_local(n):
    computed = {0: 0, 1: 1}
    def fib_inner(n):
        if n not in computed:
            computed[n] = fib_inner(n-1) + fib_inner(n-2)
        return computed[n]
    return fib_inner(n)

def fib_local_exc(n):
    computed = {0: 0, 1: 1}
    def fib_inner_x(n):
        try:
            computed[n]
        except KeyError:
            computed[n] = fib_inner_x(n-1) + fib_inner_x(n-2)
        return computed[n]

    return fib_inner_x(n)

def fib_iter(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a + b
    return a

def benchmark(n, *args):
    print("-" * 80)
    for func in args:
        print(func.__name__)
        start = clock()
        try:
            ret = func(n)
            #print("Result:", ret)
        except RuntimeError as e:
            print("Error:", e)
        print("Time:", "{:.8f}".format(clock() - start))
        print()

benchmark(500, fib_iter, fib_memo, fib_local, fib_local_exc, fib_lru)
