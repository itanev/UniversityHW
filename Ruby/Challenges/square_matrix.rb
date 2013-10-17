def zig_zag(number)
  matrix = []
  1.upto(number) do |row|
    current_row = []

    upper_limit = row * number
    lower_limit = upper_limit - number + 1

    lower_limit.upto(upper_limit) do |i|
      row % 2 == 0 ? current_row.unshift(i) : current_row << i
    end

    matrix << current_row
  end

  return matrix
end
