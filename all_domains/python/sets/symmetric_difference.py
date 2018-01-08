# -*- coding: utf8 -*-

if __name__ == '__main__':
    n1 = int(input())
    a1 = set(list(map(int, input().split())))
    n2 = int(input())
    a2 = set(list(map(int, input().split())))
    symDif = a1.symmetric_difference(a2)
    symDif = sorted(symDif)
    for elem in symDif:
        print(elem)
