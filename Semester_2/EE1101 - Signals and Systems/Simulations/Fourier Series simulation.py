import numpy as np
import matplotlib.pyplot as plt

t = np.arange(-2.01,2,0.01)
N_max = 20
N_vals = np.arange(-N_max,N_max+1)
def x_t():
    if
c_n = np.zeros_like(N_vals,dtype = complex)
for i,n in enumerate(N_vals):
    if n!=0 and n%2!=0:
        c_n[i] = (1-(-1)**(np.abs(n)))/(1.j*n*np.pi)
plt.figure(figsize=(12,5))
plt.subplot(1,2,1)
plt.stem(N_vals,np.abs(c_n),basefmt = " ")
plt.xlabel("n")
plt.ylabel("|c_n|")
plt.title("Spectrum")
plt.grid()
plt.tight_layout
plt.show()