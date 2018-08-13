#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.


def jumpingOnClouds(c, k):
    energy = 100
    ii = 0
    while ii + k < len(c):
        if c[ii + k]:
            energy -= 2
        energy -= 1
        ii += k
    ii = (ii + k) % len(c)
    if c[ii]:
        energy -= 2
    energy -= 1
    return energy


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    c = list(map(int, input().rstrip().split()))
    result = jumpingOnClouds(c, k)
    fptr.write(str(result) + '\n')
    fptr.close()
