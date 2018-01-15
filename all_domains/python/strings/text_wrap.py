# -*- coding: utf8 -*-
import textwrap

# https://docs.python.org/3.6/library/textwrap.html

def wrap(string, max_width):
    return textwrap.fill(string, max_width)


if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)
