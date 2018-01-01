# -*- coding: utf8 -*-

import math


def ComparisonFunction(listItem):
    return listItem[0]


def studentsSecondLowestScore(listOfNamesScores):
    '''Returns a list containing only the students with the second lowest
    score.'''
    # Identify lowest score. Linear complexity.
    lowestScore = math.inf
    for nameScorePair in listOfNamesScores:
        if nameScorePair[1] < lowestScore:
            lowestScore = nameScorePair[1]
    # Remove instances of the lowest score from the list. Linear complexity.
    listNoWinners = [
        ([name, score])
        for [name, score] in listOfNamesScores if score != lowestScore]
    # Identify second lowest score. Linear complexity.
    lowestScore = math.inf
    for nameScorePair in listNoWinners:
        if nameScorePair[1] < lowestScore:
            lowestScore = nameScorePair[1]
    # Remove instances of overperforming names. Linear complexity.
    listSeconds = [
        ([name, score])
        for [name, score]
        in listNoWinners
        if score == lowestScore]
    return listSeconds

if __name__ == '__main__':
    theList = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        localList = [name, score]
        theList.append(localList)
    secondGraders = studentsSecondLowestScore(theList)
    secondGraders.sort(key=ComparisonFunction)
    for nameScore in secondGraders:
        print(nameScore[0])
