import numpy as np
import matplotlib.pyplot as plt

t = np.arange(-2.01,2,0.01)
N_max = 20
T = 3
w = 2*np.pi/T
def x_t(t):
    if -1<=t<0:    return t+1
    elif 0<=t<1:    return 1
    else:   return 0
x_t_vector = np.vectorize(x_t)
N_vals = np.arange(-N_max,N_max+1)

c_n = np.zeros_like(N_vals,dtype = complex)
c_b = np.zeros_like(N_vals,dtype = complex)
c_d = np.zeros_like(N_vals,dtype = complex)
c_e = np.zeros_like(N_vals,dtype = complex)
c_f = np.zeros_like(N_vals,dtype = complex)
for i,n in enumerate(N_vals):
    real_part = lambda t: x_t_vector(t)*np.cos(n*w*t)
    imaginary_part = lambda t: x_t_vector(t)*np.sin(n*w*t)
    a_n = (2/T)*np.trapz(real_part(np.linspace(-1,1,1000)),np.linspace(-1,1,1000))
    b_n = (2/T)*np.trapz(imaginary_part(np.linspace(-1,1,1000)),np.linspace(-1,1,1000))
    c_n[i] = (a_n - (1j*b_n))/2
    c_b[i] = c_n[i] * np.exp(-1j*i*w*0.5)
    c_d[i] = c_n[i] + 1j * c_n[-i]
    c_e[i] = c_n[i] + c_n[-i]
    c_f[i] = c_n[i] - c_n[-i]


plt.figure(figsize=(12,5))
plt.subplot(2,2,1)
plt.stem(N_vals,np.abs(c_n),basefmt = " ")
plt.xlabel("n")
plt.ylabel("|c_n|")
plt.title("Magnitude Spectrum")
plt.grid()

plt.figure(figsize=(12,5))
plt.subplot(2,2,2)
plt.stem(N_vals,np.abs(c_d),basefmt = " ")
plt.xlabel("n")
plt.ylabel("|c_b|")
plt.title("Magnitude Spectrum")
plt.grid()

plt.figure(figsize=(12,5))
plt.subplot(2,2,2)
plt.stem(N_vals,np.abs(c_d),basefmt = " ")
plt.xlabel("n")
plt.ylabel("|c_d|")
plt.title("Magnitude Spectrum")
plt.grid()

plt.figure(figsize=(12,5))
plt.subplot(2,2,2)
plt.stem(N_vals,np.abs(c_d),basefmt = " ")
plt.xlabel("n")
plt.ylabel("|c_e|")
plt.title("Magnitude Spectrum")
plt.grid()

plt.figure(figsize=(12,5))
plt.subplot(2,2,2)
plt.stem(N_vals,np.abs(c_d),basefmt = " ")
plt.xlabel("n")
plt.ylabel("|c_f|")
plt.title("Magnitude Spectrum")
plt.grid()

plt.tight_layout()
plt.show()