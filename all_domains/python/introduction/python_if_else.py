# -*- coding: utf8 -*-

if __name__ == '__main__':
    n = int(input())
    if (n % 2 == 0):
        if 2 <= n and n <= 5:
            print("Not Weird")
        elif 6 <= n and n <= 20:
            print("Weird")
        else:
            print("Not Weird")
    else:
        print("Weird")
