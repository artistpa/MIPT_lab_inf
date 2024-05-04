import matplotlib.pyplot as plt
import numpy as np
import csv

with open('vector_size.csv') as f1:
    r1 = csv.reader(f1)
    x1 = []
    for line in r1:
          x1.extend(map(float, line))
with open('vector_time.csv') as f1:
    r1 = csv.reader(f1)
    y1 = []
    for line in r1:
          y1.extend(map(float, line))
with open('forward_list_size.csv') as f1:
    r1 = csv.reader(f1)
    x2 = []
    for line in r1:
          x2.extend(map(float, line))
with open('forward_list_time.csv') as f1:
    r1 = csv.reader(f1)
    y2 = []
    for line in r1:
          y2.extend(map(float, line))
with open('list_size.csv') as f1:
    r1 = csv.reader(f1)
    x3 = []
    for line in r1:
          x3.extend(map(float, line))
with open('list_time.csv') as f1:
    r1 = csv.reader(f1)
    y3 = []
    for line in r1:
          y3.extend(map(float, line))
with open('set_size.csv') as f1:
    r1 = csv.reader(f1)
    x4 = []
    for line in r1:
          x4.extend(map(float, line))
with open('set_time.csv') as f1:
    r1 = csv.reader(f1)
    y4 = []
    for line in r1:
          y4.extend(map(float, line))
with open('map_size.csv') as f1:
    r1 = csv.reader(f1)
    x5 = []
    for line in r1:
          x5.extend(map(float, line))
with open('map_time.csv') as f1:
    r1 = csv.reader(f1)
    y5 = []
    for line in r1:
          y5.extend(map(float, line))

plt.plot(x1, y1, 'b', label = "vector")
plt.plot(x2, y2, 'r', label = "forward_list")
plt.plot(x3, y3, 'g', label = "list")
plt.plot(x4, y4, 'y', label = "set")
plt.plot(x5, y5, 'k', label = "map")
plt.xlabel("size")
plt.ylabel("time, ms")
plt.title("Time of walk from size")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("walk_comparison_size_from_10_to_100000_step_100.png")
plt.show()