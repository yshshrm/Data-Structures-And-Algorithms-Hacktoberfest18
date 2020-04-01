import sys
# Let's define a recursive merge sort function.
def merge_sort(values):
  if len(values) <= 1:
    return values
  middle_index = len(values) // 2
  left_values = merge_sort(values[:middle_index])
  right_values = merge_sort(values[middle_index:])
  sorted_values = []
  left_index =right_index= 0
  while left_index < len(left_values) and right_index < len(right_values):
    if left_values[left_index] < right_values[right_index]:
      sorted_values.append(left_values[left_index])
      left_index += 1
    else:
      sorted_values.append(right_values[right_index])
      right_index += 1
  sorted_values += left_values[left_index:]
  sorted_values += right_values[right_index:]
  return sorted_values
#driver method
print (merge_sort(input("Enter A list of numbers to sortseparated by a comma: ")))
