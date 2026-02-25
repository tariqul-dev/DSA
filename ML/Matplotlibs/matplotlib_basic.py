import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 10, 100)
print(x)
print()

y = np.sin(x)
z = np.cos(x)

print(y)
print()
print(z)

plt.plot(x, y)
plt.show()

