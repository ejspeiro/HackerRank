#!/bin/python3

import math
import os
import random
import re
import sys

def computeCommonPrefixLength(s, t):
    commPrefLength = 0
    idx = 0
    while idx < min(len(s), len(t)) and s[idx] == t[idx]:
        commPrefLength += 1
        idx += 1
    return commPrefLength

# Complete the appendAndDelete function below.
def appendAndDelete(s, t, k):
    commonPrefixLength = computeCommonPrefixLength(s, t)
    if k < len(s) + len(t) - 2*commonPrefixLength:
        return "No"
    elif k%2 == (len(s) + len(t) - 2*commonPrefixLength)%2:
        return "Yes"
    elif len(s) + len(t) < k:
        return "Yes"
    else:
        return "No"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    t = input()
    k = int(input())
    result = appendAndDelete(s, t, k)
    fptr.write(result + '\n')
    fptr.close()
