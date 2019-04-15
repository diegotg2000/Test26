import numpy as np
import matplotlib.pyplot as plt



t1=np.loadtxt('rk2.txt',usecols=0)
t2=np.loadtxt('explicito.txt',usecols=0)
Y_r=np.loadtxt('rk2.txt',usecols=1)
Y_e=np.loadtxt('explicito.txt',usecols=1)
plt.plot(t1,Y_r)
plt.plot(t2,Y_e)
plt.savefig('graficas.png')