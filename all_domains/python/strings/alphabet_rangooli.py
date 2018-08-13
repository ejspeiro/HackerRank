import sys

alphabet = ['a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o',
            'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z']


def printLine(nn, distanceFromCenter):
    for ii in range(1, 2*distanceFromCenter + 1):
        sys.stdout.write("-")
    for letter in range(nn - 1, distanceFromCenter, -1):
        sys.stdout.write("{}-".format(alphabet[letter]))
    sys.stdout.write(alphabet[distanceFromCenter])
    for letter in range(distanceFromCenter + 1, nn):
        sys.stdout.write("-{}".format(alphabet[letter]))
    for ii in range(1, 2*distanceFromCenter + 1):
        sys.stdout.write("-")
    sys.stdout.write("\n")


def print_rangoli(nn):
    for distance in range(nn - 1, -1, -1):
        printLine(nn, distance)
    for distance in range(1, nn):
        printLine(nn, distance)
