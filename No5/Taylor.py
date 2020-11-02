import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from mpl_toolkits.mplot3d import Axes3D

x,t,ti = np.loadtxt("./data.txt",unpack=True)

sns.set_style("darkgrid")

fig = plt.figure()

ax=Axes3D(fig)
ax.set_xlabel("x")
ax.set_ylabel("t")
ax.set_zlabel("ti")

ax.plot(x,t,ti,marker="o",linestyle='None')

plt.show()