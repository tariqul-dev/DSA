# from functools import reduce

# li = [1, 2, 3, 4, 5]
# sum = reduce(lambda x, y: x + y, li)
# print(sum)

# import operator
# from functools import reduce

# numbers = [1, 2, 3, 4, 5]
# sum = reduce(operator.add, numbers)
# sub = reduce(operator.sub, numbers)
# mult = reduce(operator.mul, numbers)
# xor = reduce(operator.xor, numbers)

# print(f'sum: {sum}')
# print(f'sub: {sub}')
# print(f'mul: {mult}')
# print(f'xor: {xor}')

# Using initializer

# from functools import reduce
# numbers = [1, 2, 3]
# res = reduce(lambda x, y: x + y, numbers, 10)
# print(res)

# Accumulate
# from itertools import accumulate

# numbers = [1 ,2 ,3 ,4 ,5]
# res = accumulate(numbers, lambda x, y: x + y)

# print(list(res)) # 1, 3, 6, 10, 15