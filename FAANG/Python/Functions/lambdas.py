# a = "Hello world"
# upper = lambda x: x.upper()

# print(upper(a))

# Using with condition checking

# check = lambda x: "Positive" if x > 0 else "Negative" if x < 0 else "Zero"
# print(check(4))
# print(check(-1))
# print(check(0))

# Even odd
# check = lambda x: "Even" if x % 2 == 0 else "Odd"
# print(check(3))
# print(check(6)) 

# Using with list comprehension
# func = [lambda arg = x: arg * 10 for x in range(1, 5)]
# ls = [x() for x in func]
# print(func)
# print()
# print(ls)

# Using with filter()
# numbers = [x for x in range(1, 11)]
# print(f"Main list: {numbers}")
# even = list(filter(lambda x: x % 2 == 0, numbers))
# print(even)

# odd = list(filter(lambda x: x % 2 == 1, numbers))
# print(odd)

# Using with map() 
# a = [1, 2, 3, 4, 5]
# double = list(map(lambda x: x**2, a))
# print(double)

# Using with reduce()
# from functools import reduce
# numbers = [1 ,2 ,3 ,4 ,5]
# add = reduce(lambda x, y: x + y, numbers)
# print(add)