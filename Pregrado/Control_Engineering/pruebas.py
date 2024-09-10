from control.matlab import *
import matplotlib.pyplot as plt
n=[5.]
d=[1., 2., 5.]
s=tf(n,d)
print(s)
step(s)

plt.figure(1)
yout,T=step(s)
plt.plot(T.T,yout.T)