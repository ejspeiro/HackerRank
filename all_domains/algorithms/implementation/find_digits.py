#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the findDigits function below.
def findDigits(n):
    given = n
    numDivs = 0
    while n > 0:
        d = n%10
        if d > 0 and given%d == 0:
            numDivs += 1
        n = n//10
    return numDivs


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    t = int(input())
    for t_itr in range(t):
        n = int(input())
        result = findDigits(n)
        fptr.write(str(result) + '\n')
    fptr.close()
