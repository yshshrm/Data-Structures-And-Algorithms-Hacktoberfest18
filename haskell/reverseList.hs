--Recursive Style
rev [ ] = [ ]
rev (l:ls) = rev ls ++ [l]
