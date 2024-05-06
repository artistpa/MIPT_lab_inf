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

y1 = y1 / np.log(x1)
y2 = y2 / np.log(x2)
y3 = y3 / np.log(x3)
y4 = y4 / np.log(x4)
y5 = y5 / np.log(x5)

a1 = np.polyfit(x1, y1, 1)
a2 = np.polyfit(x2, y2, 1)
a3 = np.polyfit(x3, y3, 1)
a4 = np.polyfit(x4, y4, 1)
a5 = np.polyfit(x5, y5, 1)
print(a1)
print(a2)
print(a3)
print(a4)
print(a5)

#plt.plot(x1, y1, 'b', label = "subset")
plt.plot(x2, y2, 'r', label = "set")
plt.plot(x3, y3, 'g', label = "map")
plt.plot(x4, y4, 'y', label = "multiset")
plt.plot(x5, y5, 'k', label = "multimap")
plt.xlabel("size")
plt.ylabel("time / ln(size), ms")
plt.title("(Time of insert) / ln(size) from size")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("ln_insert_comparison_size_from_10_to_10000_step_10.png")
plt.show()