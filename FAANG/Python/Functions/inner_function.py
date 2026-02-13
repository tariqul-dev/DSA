# def f1(msg):
#     def f2():
#         print(msg)
    
#     f2()

# f1("Hi")


# Local variable access
# def f1():
#     msg = "Hello"
#     def f2():
#         print(msg)

#     f2()

# f1()

# Modifying variables using nonlocal
# def f1():
#     a = 3

#     def f2():
#         nonlocal a
#         a = 44
#         print(a)
    
#     f2()
#     print(a)

# f1()

# Clouser in inner function
# def f1(msg):
#     def f2():
#         print(msg)
#     return f2

# clouser = f1("hello")
# clouser()

# Encapsulation of helper function
# def processData(data):
#     def cleanData():
#         return [item.strip() for item in data]
#     return cleanData()

# print(processData(["  Python  ", "  Inner Function  "]))

# Function wrapper and logging
# import logging
# logging.basicConfig(level=logging.INFO)

# def logger(func):
#     def wrapper(*args, **kwargs):
#         logging.info(f'Excecuting {func.__name__} wit {args}, {kwargs}')
#         return func(*args, **kwargs)
#     return wrapper

# @logger
# def add(a, b):
#     return a + b

# print(add(2, 3))