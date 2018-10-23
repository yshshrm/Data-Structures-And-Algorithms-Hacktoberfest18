# Here's a function that takes three arguments.
# If the first two are zero, it returns “FizzBuzz.” If the first is zero, it returns “Fizz.”
# If the second is zero, it returns “Buzz.” Otherwise it returns the third argument.

fizz_buzz = fn
  0, 0, _ -> "FizzBuzz"
  0, _, _ -> "Fizz"
  _, 0, _ -> "Buzz"
  _, _, c -> c
end

IO.puts fizz_buzz.(0, 2, 3)
IO.puts fizz_buzz.(1, 2, 3)
IO.puts fizz_buzz.(1, 0, 3)
IO.puts fizz_buzz.(0, 0, 3)
