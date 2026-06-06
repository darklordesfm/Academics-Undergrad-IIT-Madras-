import matplotlib.pyplot as plt
import numpy as np

n = np.arange(-4,4.01,0.01)

def f(n): return np.where(n <= -1, 0, np.where(n < 0, n + 1, np.where(n < 1, 1, 0)))

f_n = f(n)
f_negn = f(-n)

f_even = (f_n + f_negn)/2
f_odd = (f_n - f_negn)/2

plt.figure(figsize=(8,6))
plt.plot(n,f(n), 'b', label = "f(n)")
plt.plot(n,f_even,'g--',label = "Even Part")
plt.plot(n,f_odd,'r--',label = "Odd Part")
plt.xlabel("n")
plt.ylabel("Values")
plt.title("Even and Odd functions")
plt.axhline(0,color = 'black',linewidth = 0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.legend()
plt.show()