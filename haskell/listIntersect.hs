-- returns from 2 lists an element in the same position with the same value
arrayIntersect :: (Ord a) => [a] -> [a] -> [a]

--base cases
arrayIntersect [] [] = []
arrayIntersect [xs] [] = []
arrayIntersect [] [ys] = []

arrayIntersect (x:xs) (y:ys)
    |(x == y) = x : arrayIntersect xs ys
    |otherwise = arrayIntersect xs ys
