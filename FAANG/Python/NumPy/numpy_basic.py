import numpy as np
# ------------- NumPy Arrays
# d1 = np.array([1, 2, 3])
# d2 = np.array([[1, 2],
#               [3, 4],
#               [5, 6]])
#
# d3 = np.array([[[1, 2], [3, 4]],
#                [[5, 6], [7, 8]],
#                [[9, 10], [11, 12]]])
#
# print(d1)
# print()
# print(d2)
# print()
# print(d3)

# ------------- NumPy Functions
# a0 = np.zeros((3, 3))
# a1 = np.ones((3, 3))
# ar = np.arange(0, 10, 2)
#
# print(a0)
# print()
# print(a1)
# print()
# print(ar)

# ------------- NumPy array slicing
# a = np.array([[1, 2, 3],
#               [4, 5, 6],
#               [7, 8, 9]])
#
# print(a[1: 2, 1:])
# print(a[0, 1])

# ------------- Advanced indexing
# a = np.array([10, 20, 30, 40, 20, 50, 60])
# idx = np.array([1, 3, 5])
#
# print(a[idx])
#
# condition =  a > 30
# print(a[condition])

# ------------- NumPy Basic Arithmetic Operations
# x = np.array([1 ,2 ,3])
# y = np.array([4, 5, 6])
#
# print(x + y)
# print(x - y)
# print(x * y)
# print(x / y)
# print(x % y)

# ------------- NumPy Unary Operation
# a = np.array([-3, -1, 0, 1, 3])
# print(np.absolute(a))

# ------------- NumPy Mathematical Function
# a = np.array([0, np.pi/2, np.pi])
# print(a)
# print(np.sin(a))
# print()
# print(np.sqrt(a))
# print()
# b = np.array([0, 1, 2, 3])
# print(np.exp(b))
# print()
# print(np.sqrt(b))

# ------------- NumPy Sorting Arrays
# dtype = [('name', 'S10'), ('year', int), ('cgpa', float)]
# vals  = [('Hrithik', 2009, 8.5),
#          ('Ajay',    2008, 8.7),
#          ('Pankaj',  2008, 7.9),
#          ('Aakash',  2009, 9.0)]
#
# a = np.array(vals, dtype=dtype)
#
# print(np.sort(a, order='name'))
# print()
# print(np.sort(a, order=['year', 'cgpa']))