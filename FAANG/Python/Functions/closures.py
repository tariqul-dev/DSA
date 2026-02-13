# def outer(x):
#     def inner(y):
#         return x + y
#     return inner
# 
# clouser = outer(10)
# print(clouser(10))
# print(clouser(20))

# def make_counter():
#     count = 0
#     def counter():
#         nonlocal count
#         count += 1
#         return count
#     return counter
# counter = make_counter()
# for i in range(5):
#     print(counter())

# def pre(p):
#     def add(t):
#         return f'{p} {t}'
#     return add
# 
# pref = pre("Hello")
# print(pref("World"))
# print(pref("there"))
# import time
# def func(a, b=[]):
#     b.append(a)
#     return b
# print(func(1))
# print(func(2))
# print(time.time())