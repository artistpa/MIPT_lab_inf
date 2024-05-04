import matplotlib.pyplot as plt
import numpy as np
import csv

with open('subset_size.csv') as f1:
    r1 = csv.reader(f1)
    x1 = []
    for line in r1:
          x1.extend(map(float, line))
with open('subset_time.csv') as f1:
    r1 = csv.reader(f1)
    y1 = []
    for line in r1:
          y1.extend(map(float, line))
with open('set_size.csv') as f1:
    r1 = csv.reader(f1)
    x2 = []
    for line in r1:
          x2.extend(map(float, line))
with open('set_time.csv') as f1:
    r1 = csv.reader(f1)
    y2 = []
    for line in r1:
          y2.extend(map(float, line))
with open('map_size.csv') as f1:
    r1 = csv.reader(f1)
    x3 = []
    for line in r1:
          x3.extend(map(float, line))
with open('map_time.csv') as f1:
    r1 = csv.reader(f1)
    y3 = []
    for line in r1:
          y3.extend(map(float, line))
with open('multiset_size.csv') as f1:
    r1 = csv.reader(f1)
    x4 = []
    for line in r1:
          x4.extend(map(float, line))
with open('multiset_time.csv') as f1:
    r1 = csv.reader(f1)
    y4 = []
    for line in r1:
          y4.extend(map(float, line))
with open('multimap_size.csv') as f1:
    r1 = csv.reader(f1)
    x5 = []
    for line in r1:
          x5.extend(map(float, line))
with open('multimap_time.csv') as f1:
    r1 = csv.reader(f1)
    y5 = []
    for line in r1:
          y5.extend(map(float, line))

plt.plot(x1, y1, 'b', label = "subset")
plt.plot(x2, y2, 'r', label = "set")
plt.plot(x3, y3, 'g', label = "map")
plt.plot(x4, y4, 'y', label = "multiset")
plt.plot(x5, y5, 'k', label = "multimap")
plt.xlabel("size")
plt.ylabel("time, ms")
plt.title("Time of insert from size")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("insert_comparison_size_from_10_to_10000_step_10.png")
plt.show()