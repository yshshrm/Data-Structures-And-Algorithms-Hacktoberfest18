ite :: (Ord a) => [a] -> Int -> [a] -> (Int,[a])
ite [x] n r = (n,r++[x])
ite (x1:x2:xs) n r | (x2 >= x1) = ite (x2:xs) n (r ++ [x1]) 
                   | otherwise = ite (x1:xs) (n+1) (r ++ [x2])
                   
bubble :: (Ord a) => [a] -> [a]
bubble x = if (g == 0) then xx else bubble xx
           where (g,xx) = ite x 0 []