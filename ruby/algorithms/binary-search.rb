def binarySearch(element, array)
  left = 0
  right = array.lenght-1
  found = false
  
  until found
    mid = (left+right)/2
    if array[mid] == element
      found = true
    elsif array[mid] < element
      left = mid+1
    else 
      right = mid-1
    end
  end
  return found
end
