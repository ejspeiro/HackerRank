# -*- coding: utf8 -*-


def count_substring(string, sub_string):
    stringLength = len(string)
    subStringLength = len(sub_string)
    countSubStr = 0
    for ii in range(0, stringLength):
        aux = string[ii] == sub_string[0]
        if aux and string[ii:ii + subStringLength] == sub_string:
            countSubStr = countSubStr + 1
    return countSubStr


if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    count = count_substring(string, sub_string)
    print(count)
