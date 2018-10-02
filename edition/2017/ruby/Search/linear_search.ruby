class LinearSearch
    # This function returns index of element x in arr[]
    def self.search(array, search_term)
      array.each_with_index do |elem, index|
        if elem == search_term
          return index 
        end
        -1
      end
    end
end


# Example
array = ['Hi', 'Hola', 'Iorana']
LinearSearch.search(array, 'Hola')   => 1
LinearSearch.search(array, 'Hi')     => 0
LinearSearch.search(array, 'Iorana') => 2
