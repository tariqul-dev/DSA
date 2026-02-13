# li = ["apple", "banana", "avocado", "cherry", "apricot"]
# res = filter(lambda s: s.startswith('a'), li)

# print(list(res))

# Filtering and Transforming Data
# a = [1, 2 , 3, 4]
# b = filter(lambda x: x % 2 ==0, a)
# c = map(lambda x:  x * 3, b)
# print(list(c))

# Filtering with None
l = ["apple", "", None, "banana", 0, "cherry", 1]
a = filter(None, l)
print(list(a))