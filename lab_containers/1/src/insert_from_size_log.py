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
x1 = np.log(x1)
x2 = np.log(x2)
y1 = np.log(y1)
y2 = np.log(y2)
a1 = np.polyfit(x1[25:], y1[25:], 1)
a2 = np.polyfit(x2[25:], y2[25:], 1)
print(a1)
print(a2)
plt.plot(x1[:len(x1) - 1], y1[:len(y1) - 1], 'b', label = "STL vector, k = 2.3")
plt.plot(x2[:len(x2) - 1], y2[:len(y2) - 1], 'r', label = "subvector, k =1.8")
plt.ylabel("ln(time), ms")
plt.xlabel("ln(size)")
plt.title("Time of insertion from size on a logarithmic scale")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("ln_insert_comparison_size_from_0_to_52000_step_1000.png")
plt.show()
