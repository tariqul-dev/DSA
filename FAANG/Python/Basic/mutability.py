# Mutable
a = [1, 2, 3]
b = a

print(a) # 1, 2, 3
print(b) # 1, 2, 3

a.append(4)

print()
print(a) # 1, 2, 3, 4
print(b) # 1, 2, 3, 4

# Immutable
x = 10
y = x
y += 1
print(x) # 10
print(y) # 11