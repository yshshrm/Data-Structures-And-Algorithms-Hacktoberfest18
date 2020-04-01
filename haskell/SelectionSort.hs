-- Polymorphic sorting
sort :: Ord a => [a] -> [a]
sort xs = selects xs

-- Repeat selection of smallest element
selects :: Ord a => [a] -> [a]
selects [] = []
selects xs = x : selects xs'
  where
    x = smallest (head xs) (tail xs)
    xs' = remove x xs

-- Find smallest element
smallest :: Ord a => a -> [a] -> a
smallest x [] = x
smallest x (y:ys) = smallest (min x y) ys

-- Remove a given element
remove :: Eq a => a -> [a] -> [a]
remove _ [] = error "Element not found for removal."
remove x (y:ys) =
  if x==y
    then ys
    else y : remove x ys
