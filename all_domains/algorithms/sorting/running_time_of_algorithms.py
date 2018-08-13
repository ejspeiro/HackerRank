#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the runningTime function below.


def runningTime(arr):
    num_shifts = 0
    l = arr
    for i in range(1, len(l)):
        j = i
        while (j > 0) and (l[j] < l[j - 1]):
            key = l[j - 1]
            l[j - 1] = l[j]
            l[j] = key
            num_shifts += 1
            j -= 1
    return num_shifts


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = runningTime(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
