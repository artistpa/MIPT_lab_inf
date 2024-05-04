import matplotlib.pyplot as plt
import numpy as np
import csv

with open('size.csv') as f1:
    r1 = csv.reader(f1)
    y1 = []
    for line in r1:
          y1.extend(map(float, line))
with open('capacity.csv') as f1:
    r1 = csv.reader(f1)
    y2 = []
    for line in r1:
          y2.extend(map(float, line))

x = np.linspace(0, 100000, 100000)
plt.plot(x, y1, 'b', label = "size")
plt.plot(x, y2, 'r', label = "capacity")
plt.ylabel("Size and capacity of vector")
plt.xlabel("Number of iteration")
plt.title("The dependence of size and capacity on iteration with reserve")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("vector_size_capacity_with_reserve.png")
plt.show()
