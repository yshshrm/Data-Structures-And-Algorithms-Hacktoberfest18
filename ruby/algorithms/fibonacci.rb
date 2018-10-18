def fib(n)
  a = 1
  b = 1
  
  for k in (0...n-2)
    a, b = b, a+b
    
  return b
end
