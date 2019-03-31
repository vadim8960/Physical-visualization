from pylab import *
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time
import math 


fig = plt.figure()

ion()

axes = fig.add_axes([0.1, 0.1, 0.8, 0.8]) # left, bottom, width, height (range 0 to 1)

x0 = sin(pi/6)
y0 = cos(pi/6)

axes.plot([x0, 0], [0, y0])
plt.grid(True)

plt.draw()
plt.pause(0.1)

t = 0

x = x0
y = y0

while y >= 0:
	y = y0 + 1/2 * t * t * (9.8 * tan(asin(y)) / ((1 + 0.1*0.05) * (1 + 0.1 * tan(asin(y))))
	x = x0 + 1/2 * t * t * (9.8 / ((1 + 0.1*0.05) * (1 + 0.1 * tan(acos(x))) ) )
	axes.plot([x, 0], [0, y])
	plt.draw()
	plt.pause(0.1)
	t += 0.1

plt.show()
time.sleep(100)
