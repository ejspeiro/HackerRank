from itertools import product
import sys

if __name__ == "__main__":
    listA = list(map(int, input().split()))
    listB = list(map(int, input().split()))
    prod = product(listA, listB)
    for tuple in prod:
        sys.stdout.write("{} ".format(str(tuple)))
