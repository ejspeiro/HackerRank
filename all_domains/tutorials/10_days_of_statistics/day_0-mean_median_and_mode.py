# -*- coding: utf8 -*-


def mean(numSamples, samples):
    return sum(samples)/numSamples


def median(numSamples, samples):
    sortedSamples = sorted(samples)
    if numSamples % 2 == 0:
        # Even number of samples.
        return (sortedSamples[numSamples//2 - 1] +
                sortedSamples[numSamples//2])/2.0
    else:
        # Odd number of samples.
        return sortedSamples[numSamples//2]


def mode(numSamples, samples):
    histogram = dict()
    # Build histogram of given samples.
    for sample in samples:
        if sample not in histogram:
            histogram[sample] = 1
        else:
            histogram[sample] += 1
    # Extract mode from histogram.
    minFreq = min(histogram.values())
    maxFreq = max(histogram.values())
    if minFreq == maxFreq:
        # Samples have all the same frequences.
        return min(histogram.keys())
    else:
        # Samples have differente frequencies.
        # Find smallest value with maxFreq frequency.
        inf = 10**6
        minFreq = inf
        for sample, freq in histogram.items():
            if freq == maxFreq and sample < minFreq:
                minFreq = sample
        return minFreq


if __name__ == '__main__':
    numSamples = int(input())
    samples = list(map(int, input().split()))
    print(mean(numSamples, samples))
    print(median(numSamples, samples))
    print(mode(numSamples, samples))
