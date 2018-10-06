## Bubble Sort example in Nim Programming Language

## bubble_sort takes an unsorted sequence of integers sort the sequence
proc bubble_sort(input: var seq[int]) =
  for i in countup(1, input.len - 1):
    for j in countdown(input.len - 1, i):
      if input[j - 1] > input[j]:
        # swap the two numbers
        var temp = input[j]
        input[j] = input[j - 1]
        input[j - 1] = temp


var input: seq[int] = @[5, 3, 6, 2, 3, 4, 5]

echo input

bubble_sort(input)
echo input