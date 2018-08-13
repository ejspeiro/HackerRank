# -*- coding: utf8 -*-

import math


def mean(numSamples, samples):
    return sum(samples)/numSamples


def standardDeviation(numSamples, samples):
    samplesMean = mean(numSamples, samples)
    numerator = sum([(xx - samplesMean)*(xx - samplesMean) for xx in samples])
    return math.sqrt(numerator/numSamples)


if __name__ == "__main__":
    numSamples = int(input())
    samples = list(map(int, input().split()))
    print("{0:.1f}".format(standardDeviation(numSamples, samples)))
