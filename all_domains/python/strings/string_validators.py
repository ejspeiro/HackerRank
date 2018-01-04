# -*- coding: utf8 -*-

if __name__ == '__main__':
    s = input()

    hasAlNum = False
    hasAlpha = False
    hasDigit = False
    hasLower = False
    hasUpper = False

    digitChecked = False
    lowerChecked = False
    upperChecked = False

    # Check every character in the string. Linear complexity.
    for cc in s:
        if ~digitChecked and cc.isdigit():
            hasDigit = True
            digitChecked = True
        if ~lowerChecked and cc.islower():
            hasLower = True
            lowerChecked = True
        if ~upperChecked and cc.isupper():
            hasUpper = True
            upperChecked = True

    if lowerChecked and upperChecked:
        hasAlpha = True

    if hasAlpha and hasDigit:
        hasAlNum = True;

    if hasAlNum:
        print(True)
    else:
        print(False)
    if hasAlpha:
        print(True)
    else:
        print(False)
    if hasDigit:
        print(True)
    else:
        print(False)
    if hasLower:
        print(True)
    else:
        print(False)
    if hasUpper:
        print(True)
    else:
        print(False)
