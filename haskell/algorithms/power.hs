power :: Int -> Int -> Int

power x 0 = 1
power x y = x * power x (y - 1)
