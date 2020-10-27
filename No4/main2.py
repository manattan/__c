import numpy as np
import matplotlib.pyplot as plt

t,i = np.loadtxt("./dataRL.txt",skiprows=1,unpack=True)

plt.plot(t,i,label="t,i")
plt.legend()
plt.show()