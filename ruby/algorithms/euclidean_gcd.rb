# Author: Ygor Sad <https://github.com/ysads>
# 
# This is an object-oriented approach to evaluate greatest
# common divisor (GCD), using Euclidean Algorithm. Further
# explanation can be read here: <https://en.wikipedia.org/wiki/Euclidean_algorithm>

class GDC

  attr_reader :alpha, :betha, :value

  def initialize(a, b)
    @a = a
    @b = b
    evaluate
  end

  def coeficients
    {
      alpha: @alpha,
      betha: @betha
    }
  end

  def to_s
    evaluate if @value.nil?
    "gdc(#{@a},#{@b}) = #{@alpha} * #{@a} + #{@betha} * #{@b} = #{@value}"
  end

  private

  def evaluate
    m = [[@a, 1, 0], [@b, 0, 1]]

    while m[1][0] != 0
      q = m[0][0] / m[1][0]
      n = [[0, 1], [1, -q]]

      m = multiply_matrix n, m
    end
    
    @alpha = m[0][1]
    @betha = m[0][2]
    @value = m[0][0]
  end

  def multiply_matrix(mat_1, mat_2)
    result = []

    lines = mat_1.length - 1
    columns = mat_2[0].length - 1
    element_count = mat_1[0].length - 1

    for i in (0..lines)
      line = []
      for j in (0..columns)
        sum = 0
        for k in (0..element_count)
          sum += mat_1[i][k] * mat_2[k][j]
        end
        line << sum
      end
      result << line
    end
    result
  end
  
end

puts GDC.new(27, 9)
puts GDC.new(81, 4)
puts GDC.new(121, 77)
