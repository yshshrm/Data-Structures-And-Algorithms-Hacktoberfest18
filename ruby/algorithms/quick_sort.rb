def qsort(arr)
  return [] if arr.empty?
  pivot = arr.pop
  left, right = arr.partition(&pivot.method(:>))
  return *qsort(left), pivot, *qsort(right)
end
