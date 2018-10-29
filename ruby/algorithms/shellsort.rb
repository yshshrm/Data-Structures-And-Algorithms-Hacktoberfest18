class Array
  def shellsort!
    inc = length / 2
    while inc != 0
      inc.step(length-1) do |i|
        el = self[i]
        while i >= inc and self[i - inc] > el
          self[i] = self[i - inc]
          i -= inc
        end
        self[i] = el
      end
      inc = (inc == 2 ? 1 : (inc * 5.0 / 11).to_i)
    end
    self
  end
end
