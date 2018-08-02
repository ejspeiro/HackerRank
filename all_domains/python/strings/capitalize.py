#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the solve function below.
def solve(s):
    capitalizedName = s[0].capitalize()
    for char in range(1, len(s)):
        if s[char] != " " and s[char - 1] == " ":
            capitalizedName += s[char].capitalize()
        else:
            capitalizedName += s[char]
    return capitalizedName

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = solve(s)
    fptr.write(result + '\n')
    fptr.close()
