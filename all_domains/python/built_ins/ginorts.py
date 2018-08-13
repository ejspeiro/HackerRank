if __name__ == '__main__':
    theString = input()
    lower = list()
    upper = list()
    odd = list()
    even = list()
    for character in theString:
        if character.isdigit():
            if int(character) % 2 == 0:
                even.append(int(character))
            else:
                odd.append(int(character))
        else:
            if character.isupper():
                upper.append(character)
            else:
                lower.append(character)
    finalStr = str()
    finalList = sorted(lower) + sorted(upper) + sorted(odd) + sorted(even)
    for item in finalList:
        finalStr += str(item)
    print(finalStr)
