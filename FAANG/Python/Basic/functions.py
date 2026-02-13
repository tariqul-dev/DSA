def f(x):
    x.append(4)

ls = [1, 2, 3]
f(ls)
print(ls) # 1, 2, 3, 4

# But
def fun(x):
    x = x + [4]
    print(x) # 1, 2, 3, 4

lst = [1, 2, 3]
fun(lst)
print(lst) # 1, 2, 3
