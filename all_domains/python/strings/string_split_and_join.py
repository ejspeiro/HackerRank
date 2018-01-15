# -*- coding: utf8 -*-


def split_and_join(line):
    # Return a list of the words in the string, using a space as the delimiter.
    line = line.split(" ")
    # Return a string which is the concatenation of the strings in argument.
    return "-".join(line)


if __name__ == '__main__':
    line = raw_input()
    result = split_and_join(line)
    print result
