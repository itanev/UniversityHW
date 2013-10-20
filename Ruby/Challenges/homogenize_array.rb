def homogenize(list)
  hash = {}
  list.each { |item| hash.has_key?(item.class) ? hash[item.class] << item : hash[item.class] = [] << item }
  hash.values
end
