def lineal_search(array,x)
  found = false
  i = 0
  while i < array.lenght && !found 
    if(array[i]==x)
      found = true
      i++
    end
  end
  return found
end
