import sympy as sp
import numpy as np
import matplotlib.pyplot as plt
from sympy.physics.units import frequency

t,n = sp.symbols('t n',real=True,integer='True')
T = 1
x_t = sp.cos(10*sp.pi*t) + sp.cos(6*sp.pi*t)
n = sp.symbols('n',integer = True)
c_n = 1/T * sp.integrate(x_t*sp.exp(-sp.I*2*sp.pi*n*t/T),(t,-3,3))
N = 10
frequency = np.arange(-N,N+1)
c_n_val = np.array([complex(c_n.subs(n,k)) for k in frequency])
magnitude = np.abs(c_n_val)
plt.stem(frequency,magnitude)
plt.xlabel='n'
plt.ylabel='|c_n|'
plt.grid()
plt.show()