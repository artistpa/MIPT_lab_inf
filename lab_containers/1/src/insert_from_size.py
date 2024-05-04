import matplotlib.pyplot as plt
import numpy as np
import csv

with open('standard_vector_size.csv') as f1:
    r1 = csv.reader(f1)
    x1 = []
    for line in r1:
          x1.extend(map(float, line))
with open('standard_vector_time.csv') as f1:
    r1 = csv.reader(f1)
    y1 = []
    for line in r1:
          y1.extend(map(float, line))
with open('subvector_size.csv') as f1:
    r1 = csv.reader(f1)
    x2 = []
    for line in r1:
          x2.extend(map(float, line))
with open('subvector_time.csv') as f1:
    r1 = csv.reader(f1)
    y2 = []
    for line in r1:
          y2.extend(map(float, line))

plt.plot(x1, y1, 'b', label = "STL vector")
plt.plot(x2, y2, 'r', label = "subvector")
plt.ylabel("time, ms")
plt.xlabel("size")
plt.title("Time of insertion from size")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("insert_comparison_size_from_2_to_1500.png")
plt.show()
