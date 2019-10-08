merge :: (Ord l) => [l] -> [l] -> [l]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) | x < y     = x:merge xs (y:ys)
                    | otherwise = y:merge (x:xs) ys

mergeSort :: (Ord l) => [l] -> [l]
mergeSort [] = []
mergeSort [l] = [l]
mergeSort l =
  merge (mergeSort left) (mergeSort right)
    where left = take ((length l) `div` 2) l
          right = drop ((length l) `div` 2) l

-- Demonstration
main = print(mergeSort([5,2,6,4,8,1,2]))
