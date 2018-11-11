#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the viralAdvertising function below.


def viralAdvertising(n):
    shared = 5
    liked = shared//2
    total_likes = liked
    for day in range(2, n + 1):
        shared = 3*liked
        liked = shared//2
        total_likes += liked
    return total_likes


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    result = viralAdvertising(n)
    fptr.write(str(result) + '\n')
    fptr.close()
