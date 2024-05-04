import matplotlib.pyplot as plt
import numpy as np
import csv

with open('subforwardlist_size.csv') as f1:
    r1 = csv.reader(f1)
    x1 = []
    for line in r1:
          x1.extend(map(float, line))
with open('subforwardlist_time.csv') as f1:
    r1 = csv.reader(f1)
    y1 = []
    for line in r1:
          y1.extend(map(float, line))
with open('list_size.csv') as f1:
    r1 = csv.reader(f1)
    x2 = []
    for line in r1:
          x2.extend(map(float, line))
with open('list_time.csv') as f1:
    r1 = csv.reader(f1)
    y2 = []
    for line in r1:
          y2.extend(map(float, line))
with open('forward_list_size.csv') as f1:
    r1 = csv.reader(f1)
    x3 = []
    for line in r1:
          x3.extend(map(float, line))
with open('forward_list_time.csv') as f1:
    r1 = csv.reader(f1)
    y3 = []
    for line in r1:
          y3.extend(map(float, line))

plt.plot(x1[1:], y1[1:], 'b', label = "subforwardlist")
plt.plot(x2[1:], y2[1:], 'r', label = "list")
plt.plot(x3[1:], y3[1:], 'g', label = "forwardlist")
plt.xlabel("size")
plt.ylabel("time, ms")
plt.title("Time of push_forward from size")
plt.minorticks_on()
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.legend()
plt.savefig("push_forward_comparison_size_from_100_to_10000_step_100.png")
plt.show()