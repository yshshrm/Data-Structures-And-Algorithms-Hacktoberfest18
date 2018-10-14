maxlcs xs ys = if length xs > length ys then xs else ys

lcs [] _ = []
lcs _ [] = []
lcs xs ys =
  if last xs == last ys 
  then lcs (init xs) (init ys) ++ [last xs]
  else uncurry maxlcs (lcs xs (init ys), lcs (init xs) ys)
