# -*- coding: utf8 -*-


def average(array):
    setHeights = set(array)
    return sum(setHeights)/len(setHeights)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
