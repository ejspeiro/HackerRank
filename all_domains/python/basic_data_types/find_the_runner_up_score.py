# -*- coding: utf8 -*-

import math

if __name__ == '__main__':
    nn = int(input())
    vals = list(map(int, input().split()))
    firstPlace = max(vals)
    secondPlace = -math.inf
    for vv in vals:
        if vv != firstPlace and vv > secondPlace:
            secondPlace = vv
    print(secondPlace)
