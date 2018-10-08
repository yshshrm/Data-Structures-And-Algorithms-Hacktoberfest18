def fib(n : Int32) : Int32
  case n
  when 0
    0
  when 1
    1
  else
    fib(n - 1) + fib(n - 2)
  end
end
