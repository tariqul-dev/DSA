# s = ['1', '2', '3', '4']
# _iter = map(int, s)
# print(list(_iter))

# celsius = [0, 20, 37, 100]
# fahrenheit = map(lambda c: (c * 9/5) + 32, celsius)
# print(list(fahrenheit))
# print(celsius)

a = [1, 2, 3]
b = [4, 5]
res = map(lambda x, y: x + y, a, b)

print(list(res))
print(list(res))