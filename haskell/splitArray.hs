-- split an array of Strings into two separate arrays of Strings
splitArray :: [String] -> ([String], [String])
splitArray [] = ([], [])
splitArray (x:xs) = (x:odd, even)
  where (even, odd) = splitArray xs