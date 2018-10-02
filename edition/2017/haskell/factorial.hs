main = print $ factorial 4

factorial 0 = 1

factorial n = factorial(n - 1) * n