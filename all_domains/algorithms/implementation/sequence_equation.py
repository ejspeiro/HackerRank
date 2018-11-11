#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the permutationEquation function below.


def permutationEquation(p):
    result = []
    for xx in range(1, len(p) + 1):
        for yy in range(1, len(p) + 1):
            if p[p[yy - 1] - 1] == xx:
                result.append(yy)
                break
    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    p = list(map(int, input().rstrip().split()))
    result = permutationEquation(p)
    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')
    fptr.close()
