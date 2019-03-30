from pylab import *
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time


fig = plt.figure()

ion()

axes = fig.add_axes([0.1, 0.1, 0.8, 0.8]) # left, bottom, width, height (range 0 to 1)

x = sin(pi/6)
y = cos(pi/6)

axes.plot([x, 0], [0, y])
plt.grid(True)

plt.draw()
plt.pause(0.1)

time.sleep(2)

axes.plot([x+1, 0], [0, y+1])

plt.draw()
plt.pause(0.1)

plt.show()
time.sleep(100)
