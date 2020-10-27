import numpy as np
import matplotlib.pyplot as plt

t,x,v = np.loadtxt("./data.txt",skiprows=1,unpack=True)

plt.plot(t,x,label="t,x")
plt.plot(t,v,label="t,v")
# plt.plot(x,v)
plt.legend()
plt.show()

# x=1
# v=0
# dt=0.01
# tmax=10