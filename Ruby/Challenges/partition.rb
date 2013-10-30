def partition(number)
  pairs = []
  counter = 0
  number = number.abs
  even = number % 2 == 0 && number != 0

  begin
    pairs << [number, counter]
    number -= 1
    counter += 1
  end while(counter < number)

  pairs << [number, number] if even

  pairs
end
