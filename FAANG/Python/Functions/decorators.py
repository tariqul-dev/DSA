# --------- Function decorator ---------

# def simple_decorator(func):
#     def wrapper():
#         print('Starting function')
#         func()
#         print('Function finished')
#     return wrapper

# @simple_decorator
# def sayHello():
#     print("Hello")

# sayHello()

# --------- Method decorator ---------

# def method_decorator(func):
#     def wrapper(*args, **kwargs):
#         print(f"{func.__name__} starting")
#         result = func(*args, **kwargs)
#         print(f"{func.__name__} finished")
#         return result
#     return wrapper

# class TestClass:
#     @method_decorator
#     def say_hello(self):
#         print("hello")

# obj = TestClass()
# obj.say_hello()

# --------- Class decorators ---------
 
# def fun(cls):
#     cls.class_name = cls.__name__
#     return cls
# @fun
# class Person:
#     pass
# print(Person.class_name)

# --------- built in decorators ---------

# staticmethod
# class Calculator:
#     @staticmethod
#     def add(x, y):
#         return x + y
    
# res = Calculator.add(4, 5)
# print(res)

# class Employee:
#     raise_amount = 50.0
#     def __init__(self, name, salary):
#         self.name = name
#         self.salary = salary

#     @classmethod
#     def set_raise_amount(cls, amont):
#         cls.raise_amount = amont

# Employee.set_raise_amount(30)
# print(Employee.raise_amount)


# class Circle:
#     def __init__(self, radius):
#         self._radius = radius

    
#     @property
#     def radius (self):
#         return self._radius
    
#     @radius.setter
#     def radius(self, radius):
#         self._radius = radius
    
#     @property
#     def area(self):
#         return 3.14 * (self._radius ** 2)

# c = Circle(5)
# print(c.radius)
# print(c.area)
# c.radius = 10
# print(c.area)

# --------- Chaining multiple decorators ---------
# def decor1(func):
#     def inner():
#         x = func()
#         return x * x
#     return inner

# def decor(func):
#     def inner():
#         x = func()
#         return 2 * x
#     return inner

# @decor1
# @decor
# def input():
#     return 10

# @decor
# @decor1
# def input2():
#     return 10

# print(input())
# print(input2())

import functools

def decorator(func):
    @functools.wraps(func)
    def wrapper():
        return func()
    return wrapper

@decorator
def greet():
    """Docstring for greet"""
    return "Hello there"

print(greet.__name__)
print(greet.__doc__)
