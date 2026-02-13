a = 10
b = a

print(id(a))
print(id(b))

print(id(a) == id(b))

a = 20
print()
print(id(a))
print(id(b))
print(id(a) == id(b))

