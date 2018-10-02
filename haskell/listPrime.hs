primes = filterPrime [2..]
      where filterPrime (p:xs) = p : filterPrime [ x | x <- xs, x `mod` p /= 0]

getNPrime :: Int -> [Int]
getNPrime n = take n primes
