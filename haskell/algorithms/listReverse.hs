listReverse ::  [a] -> [a]

listReverse [] = []
listReverse [t] = [t]
listReverse (x:t) = listReverse(t) ++ [x]
