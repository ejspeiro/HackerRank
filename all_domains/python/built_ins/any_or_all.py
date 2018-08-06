def isPal(number):
    if len(number) == 1:
        return True
    frontIdx = 0
    backIdx = len(number) - 1
    while frontIdx != backIdx and number[frontIdx] == number[backIdx]:
        frontIdx += 1
        backIdx -= 1
    if frontIdx == backIdx:
        return True
    else:
        return False

if __name__ == '__main__':
    numItems = int(input())
    numbersStr = input().split()
    numbers = map(lambda nn: int(nn) > 0, numbersStr)
    if all(numbers):
        for number in numbersStr:
            if isPal(number):
                print(True)
                exit()
        print(False)
    else:
        print(False)
