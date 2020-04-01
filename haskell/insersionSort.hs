insersionSort :: (Ord a) => [a] -> [a]
insersionSort [] = []
insersionSort (x:xs) = insertElement x (insersionSort xs)

insertElement :: (Ord a) => a -> [a] -> [a]
insertElement x [] = [x]
insertElement x (y:ys) = if (x <= y)
                        then x:y:ys
                        else y:insertElement x ys
