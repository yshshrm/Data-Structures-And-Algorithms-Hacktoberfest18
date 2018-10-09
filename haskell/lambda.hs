--Exemplos de expressoes lambda
square = \x -> x*x

--Implemente as funções anteriormente escritas usando expressões lambda
--consulte suas implementacoes anteriores para a documentacao dessas funcoes

fix :: (a -> a) -> a
fix f = f (fix f)

pow x y | y < 0 = (\a b -> 1/(pow a (-b))) x y
        | y > 0 = (\a b -> a * pow a (b-1)) x y
        | otherwise = 1 

fatorial = \x -> if x == 0 then 1 else x * (fatorial (x-1))

isPrime = \x -> [1,x] == [y | y <- [1..x], x `mod` y == 0]   

fib = \x -> if x <= 2 then 1 else (fib (x-1)) + (fib (x-2))

mdc x y | x == 0 = y
        | y == 0 = x
        |otherwise = (\x y -> if x > y then mdc (x-y) y else mdc x (y-x)) x y

mmc = \x y -> head [z | z <- [(max x y)..(x * y)], z `mod` x == 0, z `mod` y == 0]

coprimo = \x y -> (mdc x y) == 1  

goldbach = \x -> head [(a,b)| a <- [1..x], b <- [1..x], isPrime a, isPrime b, a + b == x] 

--Implemente as funções sobre listas escritas previsamente usando expressões lambda
--consulte suas implementacoes anteriores para a documentacao dessas funcoes

meuLast xs = case xs of [] -> error "Lista vazia!"
                        (h:t) -> (\h t -> if t == [] then h else meuLast t) h t

penultimo [] = error "Lista sem penultimo"
penultimo [x] = error "Lista sem penultimo" 
penultimo xs = (\i -> meuLast i) (init xs) 

elementAt = \i xs -> if (i == 1) then head xs else elementAt (i-1) (tail xs)

meuLength = \xs -> case xs of [] -> 0
                              (h:t) -> 1 + meuLength t 

meuReverso = \xs -> case xs of [] -> []
                               [x] -> [x]
                               (h:t) -> (meuReverso t) ++ [h]

isPalindrome :: Eq a => [a] -> Bool                               
isPalindrome = \xs -> xs == meuReverso xs  

compress :: Eq a => [a] -> [a] 
compress = \xs -> case xs of [] -> []
                             xs -> if elem (last xs) (init xs) then compress (init xs) else (compress (init xs)) ++ [last xs] 

compact :: Eq a => [a] -> [a]
compact = \xs -> case xs of [] -> []
                            [x] -> [x]
                            (h:t) -> if (elem h t) then [h] ++ [h] ++ (compact (remove h t)) else [h] ++ (compact t)

remove :: Eq a => a -> [a] -> [a]
remove = \x xs -> case xs of [] -> []
                             (h:t) -> if x == h then t else [h] ++ remove x t                            

encode :: Eq a => [a] -> [(a,Int)]
encode = \xs -> case xs of [] -> []
                           (h:t) -> (h, (length(filter (== h) xs)) ) : encode (filter (/= h) (h:t)) 

split = (\xs i -> [take i xs] ++ [drop i xs])

slice = (\xs imin imax -> drop (imin - 1) (take imax xs))

insertAt = \el pos (x:xs) -> if pos == 1 then [el] ++ (x:xs) else [x] ++ insertAt el (pos - 1) xs

sort :: Ord a => [a] -> [a]
sort = \xs -> case xs of [] -> []
                         xs -> minimum xs : sort (remove (minimum xs) xs)

mySum :: ([Int] -> Int)
mySum = \xs -> foldr (+) 0 xs

maxList = \xs -> if xs == [] then undefined else foldr max 0 xs


buildPalindrome = \xs -> if (length xs == 0) then xs else [head xs] ++ (buildPalindrome xs) ++ [head xs]

mean = \xs -> mySum xs `div` length xs 

myAppend :: ([a] -> [a] -> [a])
myAppend = \xs ys -> foldr (:) ys xs