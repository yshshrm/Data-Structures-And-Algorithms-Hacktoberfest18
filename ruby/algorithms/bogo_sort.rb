def bogo_sort(array)
    bogo_sort(array.shuffle!) unless (0..array.count-2).none?{|v| array[v] >= array[v+1] }
    array
end