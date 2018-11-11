#!/bin/python3

import math
import os
import random
import re
import sys


def twoStrings(s1, s2):
    letters = "abcdefghijklmopqrstuvwxyz"
    for ii in range(len(letters)):
        if letters[ii] in s1 and letters[ii] in s2:
            return "YES"
    return "NO"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    q = int(input())
    for q_itr in range(q):
        s1 = input()
        s2 = input()
        result = twoStrings(s1, s2)
        fptr.write(result + '\n')
    fptr.close()
