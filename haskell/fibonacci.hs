-- Find the nth Fibonacci number starting at 0

-- base cases 0 and 1 and otherwise Naive solution
    fib :: Int -> Int 
    fib 0 = 0
    fib 1 = 1 
    fib n = fib (n - 1) + fib (n - 2)
