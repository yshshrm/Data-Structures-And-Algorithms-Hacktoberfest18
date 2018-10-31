listSum :: [Int] -> Int

listSum [] = 0
listSum [x] = x
listSum (x:t) = x + listSum t
