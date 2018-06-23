# -*- coding: utf8 -*-


def printMiddleLine(n, m):
    numCharsWelcome = 7
    for ii in range((m - numCharsWelcome)/2 + 1):
        print("-")
    print("WELCOME")
    for ii in range((m - numCharsWelcome)/2 + 1):
        print("-")


if __name__ == '__main__':
    s = input()
    n = int(s[0])
    m = int(s[2])
    printMiddleLine(n, m)
