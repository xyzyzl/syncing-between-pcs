"""
TASK: fence9
LANG: PYTHON3
ID: albert.28
"""

import math
import sys

fin = open("fence9.in", "r")
fout = open("fence9.out", "w")

n, m, p = fin.readline().split()
fin.close()
n = float(n)
m = float(m)
p = float(p)

def line1(x) :
    return math.floor(m/n*x-0.000000001)
def line2(x) :
    return math.floor(m*(x-n)/(n-p) + m-0.000000001)
def linux(x) :
    return math.floor(m*(x-n)/(n-p) + m)

tot = 0
if m == 0 :
    fout.write("0\n")
    sys.exit()

if n == 0 :
    # cry because then we don't find the line for n since it's just x = 0. if we do anything it will be floating point error
    for i in range(1, int(p)) :
        tot += line2(i)
    fout.write(str(tot) + "\n")
    sys.exit()
if n == p :
    # be happy because we don't need line2
    for i in range(1, int(p)) :
        tot += line1(i)
    fout.write(str(tot) + "\n")
    sys.exit()

if m != 0 and n != 0 and p != 0 :
    for i in range(1, int(n)) :
        tot += line1(i)
    for i in range(min(int(n), int(p)), max(int(n), int(p))) :
        tot += -linux(i) if (n-p > 0) else line2(i)
fout.write(str(tot) + "\n")
