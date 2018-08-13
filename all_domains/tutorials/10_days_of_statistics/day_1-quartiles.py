# -*- coding: utf8 -*-


def sortedMedian(numSamples, sortedSamples):
    if numSamples % 2 == 0:
        # Even number of samples.
        return (sortedSamples[numSamples//2 - 1] +
                sortedSamples[numSamples//2])/2.0
    else:
        # Odd number of samples.
        return sortedSamples[numSamples//2]


if __name__ == "__main__":
    numSamples = int(input())
    samples = list(map(int, input().split()))
    sortedSamples = sorted(samples)

    # Compute quartiles.
    q1 = sortedMedian(numSamples//2, sortedSamples)
    q2 = sortedMedian(numSamples, sortedSamples)
    if numSamples % 2 == 0:
        q3 = sortedMedian(numSamples//2, sortedSamples[numSamples//2:])
    else:
        q3 = sortedMedian(numSamples//2, sortedSamples[numSamples//2 + 1:])

    print("{0:.0f}".format(q1))
    print("{0:.0f}".format(q2))
    print("{0:.0f}".format(q3))
