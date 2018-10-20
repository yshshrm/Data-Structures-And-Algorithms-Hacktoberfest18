-- Factorization without using any library functions
-- module MyModule

-- where 

-- divdes denominator numbertodivide 
divides :: Integral a => a -> a -> Bool 
divides d n = rem n d == 0

-- least divisor function
ld :: Integer -> Integer
ld n = ldf 2 n

-- (inner) least divisor function implementation
ldf :: Integer -> Integer -> Integer
ldf k n | divides k n = k
        | k^2 > n = n
        | otherwise = ldf (k+1) n

factors :: Integer -> [Integer]
factors n | n < 0 = error "negative number"
          | n <= 1 = []
          | otherwise = p : factors (div n p) where p = ld n

