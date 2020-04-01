--Fold Left without Identitity
foldl' _ [x:[]] = x
foldl' f (x0:x1:xs) = foldl' f ((f x0 x1):xs)

--Fold Right without Identitity
foldr' _ [x:[]] = x
foldr' f (x:xs) = f x (foldr' f xs)
