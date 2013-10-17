class Integer
  def zero?
    self == 0
  end

  def remainder(number)
    self % number
  end

  def negative?
    self < 0
  end

  def prime?
    divisor = 2
    return false if negative?

    2.upto(Math.sqrt(self)) do |divisor|
      return false if remainder(divisor).zero? or negative?
    end

    true
  end

  def generate_factors(number, factors=[])
    return factors if number == 1
    new_factor = (2..number).find {|factor| number.remainder(factor).zero? }
    generate_factors(number / new_factor, factors << new_factor)
  end

  def prime_factors
    generate_factors(self.abs)
  end

  def harmonic
    sum = 0r
    1.upto(self) do |number|
      sum += 1r / number
    end

    sum
  end

  def digits
    digits = []
    number = abs
    while number >= 1
      digits.unshift(number % 10)
      number /= 10
    end

    digits
  end
end

class Array
  def frequencies
    hash = Hash.new(0)
    each{ |item| hash[item] += 1 }

    hash
  end

  def average
    sum = 0.to_f
    each { |item| sum += item }

    sum / size
  end

  def drop_every(number)
    remaining_elements = []
    0.upto(size) do |i|
      return remaining_elements if not self[i]
      remaining_elements << self[i] unless (i + 1).remainder(number).zero?
    end

    remaining_elements
  end

  def combine_with(other)
    combined = []
    size = self.size >= other.size ? self.size : other.size
    0.upto(size) do |i|
      combined << self[i] unless i >= self.size
      combined << other[i] unless i >= other.size
    end

    combined
  end
end
