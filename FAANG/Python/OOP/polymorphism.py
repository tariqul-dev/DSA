# ------------ Compile time polymorphism ------------
# class Calculator:
#     def __init__(self):
#         pass
# 
#     def multi(self, a = 1, b = 2, *args):
#         result = a * b
#         for x in args:
#             result *= x
#         return result
# 
# cal = Calculator()
# print(cal.multi())
# print(cal.multi(4))
# print(cal.multi(1, 2, 3, 4))

# ------------ Run time polymorphism ------------
# class Animal:
#     def sound(self):
#         print("Generic sound")
#  
# class Dog(Animal):
#     def sound(self):
#         print("Dog sound")
# 
# class Cat(Animal):
#     def sound(self):
#         print("Cat sound")
# 
# animals = [Dog(), Cat(), Animal()]
# 
# for animal in animals:
#     animal.sound()

