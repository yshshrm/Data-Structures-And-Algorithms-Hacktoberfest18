proc insertion_sort(arr: var seq[int]) = 
  for i in 0..<(arr.len - 1):
    var min = arr[i]
    var min_idx = i

    for j in i..<(arr.len):
      if arr[j] < min:
        min = arr[j]
        min_idx = j
    
    echo arr
    
    if min_idx != i:
      var temp = arr[i]
      arr[i] = arr[min_idx]
      arr[min_idx] = temp
  
var arr = @[5, 7, 4, 8, 2, 6, 3]

insertion_sort(arr)

echo arr