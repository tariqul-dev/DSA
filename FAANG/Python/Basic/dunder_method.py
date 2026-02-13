import this

a = 1
b = 2

print(a.__add__(b))

ls = [1, 2, 3, 4]
print(ls.__len__())
print(ls.__getitem__(1))

def fun(x):
    print(x + 1)

fun(2)
x = fun
fun.__call__(7)
x.__call__(10)
