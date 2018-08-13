#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the circularArrayRotation function below.


def circularArrayRotation(a, k, queries):
    nn = len(a)
    results = []
    for query_idx in queries:
        a_rot = [0 for ii in range(nn)]
        # Create version of a after k rotations.
        for ii in range(nn):
            rot_ii = (ii + k) % nn
            a_rot[rot_ii] = a[ii]
        results.append(a_rot[query_idx])
    return results


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nkq = input().split()
    n = int(nkq[0])
    k = int(nkq[1])
    q = int(nkq[2])
    a = list(map(int, input().rstrip().split()))
    queries = []
    for _ in range(q):
        queries_item = int(input())
        queries.append(queries_item)
    result = circularArrayRotation(a, k, queries)
    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')
    fptr.close()
