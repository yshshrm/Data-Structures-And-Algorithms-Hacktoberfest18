# Author: Ygor Sad <https://github.com/ysads>
# 
# This is an object-oriented approach to evaluate EgyptianFractions
# starting from conventional Fraction. The main idea is to represent
# a non-one-numerator fraction using a sum of one-numerator fractions.
# Better explanation on what Egyptian Fractions are and what they are
# used for can be found here: <https://en.wikipedia.org/wiki/Egyptian_fraction>.

class Fraction

  attr_accessor :numerator, :denominator

  def initialize(numerator, denominator)
    @numerator = numerator
    @denominator = denominator
  end

  def reduce
    gcd = @numerator.gcd(denominator)
    @numerator /= gcd
    @denominator /= gcd
    self
  end

  def self.sum(f1, f2)
    a = f1.numerator
    b = f1.denominator
    c = f2.numerator
    d = f2.denominator

    Fraction.new((a * d) + (b * c), (b * d))
  end

  def self.subtract(f1, f2)
    f2 = Fraction.new(-f2.numerator, f2.denominator)    
    sum(f1, f2)
  end

  def to_s
    "#{numerator}/#{denominator}"
  end
end


class EgyptianFraction

  attr_accessor :fractions

  def initialize(base_fraction)
    @fractions = []
    base_fraction.reduce

    if base_fraction.numerator == 1
      @fractions << base_fraction 
    else
      quoc = (base_fraction.denominator / base_fraction.numerator) + 1
      frac = Fraction.new(1, quoc)

      @fractions << frac

      next_frac = Fraction.subtract(base_fraction, frac)
      @fractions += EgyptianFraction.new(next_frac).fractions
    end

    @fractions
  end

  def to_s
    @fractions.map(&:to_s).join(' + ')
  end
end


puts f1 = Fraction.new(2, 3)
puts f2 = Fraction.new(2, 8)
puts f4 = Fraction.new(5, 121)
puts f3 = Fraction.subtract(f1, f2)

puts EgyptianFraction.new(f1)
puts EgyptianFraction.new(f4)
