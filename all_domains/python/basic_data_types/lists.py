# -*- coding: utf-8 -*-

if __name__ == '__main__':
    # Constant for constant-time identification of a given command.
    INSERT_2 = "n"
    INSERT_3 = "s"
    PRINT_2 = "r"
    PRINT_3 = "i"
    REMOVE_2 = "e"
    REMOVE_3 = "m"
    APPEND_2 = "p"
    APPEND_2 = "p"
    SORT_2 = "o"
    SORT_3 = "r"
    POP_1 = "o"
    POP_2 = "p"
    REVERSE_1 = "e"
    REVERSE_2 = "v"

    N = int(input())

    theList = []

    for commandNumber in range(0, N):
        # Strings may also be created from other objects using the str
        # constructor.
        command = str(input())
        # Return a list of the words in the string.
        commandParts = command.split()
        # Isolate the first two letters of each command.
        com2 = commandParts[0][1]
        com3 = commandParts[0][2]
        # Compare given letters to realize given command in constant time.
        if com2 == INSERT_2 and com3 == INSERT_3:
            positionToInsert = commandParts[1]
            objectToInsert = commandParts[2]
            theList.insert(int(positionToInsert), int(objectToInsert))
        elif com2 == PRINT_2 and com3 == PRINT_3:
            print(theList)
        elif com2 == REMOVE_2 and com3 == REMOVE_3:
            objectToRemove = commandParts[1]
            theList.remove(int(objectToRemove))
        elif com2 == APPEND_2 and com3 == APPEND_2:
            objectToAppend = commandParts[1]
            theList.append(int(objectToAppend))
        elif com2 == SORT_2 and com3 == SORT_3:
            theList.sort()
        elif com2 == POP_1 and com3 == POP_2:
            theList.pop()
        elif com2 == REVERSE_1 and com3 == REVERSE_2:
            theList.reverse()
        else:
            print("Unknown given")
