import random

# data = [1, 2, 3, 4]

# for x in data:
#     print(x)

# print()

# _it = iter(data)

# while True:
#     try:
#         x = next(_it)
#         print(x)
#     except StopIteration:
#         break

# f = open('data.txt')

# for lines in f:
#     print(lines) # Read the content from the file

# for lines in f:
#     print(lines) # Empty

# it = iter(lambda: random.randint(1, 10), 7)

# for x in it:
#     print(x)

# Generators: Iterators with memory

# def countUpTo(n): 
#     i = 0
#     while i < n:
#         yield i
#         i += 1

# count = countUpTo(5)

# for x in count:
#     print(x)

# Generators are lazy by design

# def readLines(path):
#     with open(path) as f:
#         for line in f:
#             yield line


# g = readLines('data.txt')

# for x in g:
#     print(x)

# Generator exhaustion

# g = (x * x for x in range(3))

# print(list(g))
# print(list(g))

# print()

# def gen():
#     for x in range(3):
#         yield x * x

# print(list(gen()))
# print(list(gen()))

# yield from

# def chain (a, b):
#     yield from a
#     yield from b
    
#     # Equivalent to
#     # for x in a:
#     #     yield x
#     # for x in b:
#     #     yield x

# ls = chain([1, 2], [3, 4])

# for x in ls:
#     print(x)

from itertools import islice

pl = islice((x * x for x in range(10_000_000)), 10)

print(pl)

for x in pl:
    print(x)