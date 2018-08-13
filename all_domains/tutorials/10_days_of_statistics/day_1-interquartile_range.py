# -*- coding: utf8 -*-


def assemblePopulation(samples, frequencies):
    population = list()
    for ii in range(len(samples)):
        for jj in range(1, frequencies[ii] + 1):
            population.append(samples[ii])
    return population


def sortedMedian(numSamples, sortedSamples):
    if numSamples % 2 == 0:
        # Even number of samples.
        return (sortedSamples[numSamples//2 - 1] +
                sortedSamples[numSamples//2])/2.0
    else:
        # Odd number of samples.
        return sortedSamples[numSamples//2]


def interQuartileRange(numSamples, population):
    sortedPopulation = sorted(population)
    # Compute 1st and 3rd quartiles.
    q1 = sortedMedian(numSamples//2, sortedPopulation)
    if numSamples % 2 == 0:
        q3 = sortedMedian(numSamples//2, sortedPopulation[numSamples//2:])
    else:
        q3 = sortedMedian(numSamples//2, sortedPopulation[numSamples//2 + 1:])
    return q3 - q1


if __name__ == "__main__":
    numSamples = int(input())
    samples = list(map(int, input().split()))
    frequencies = list(map(int, input().split()))
    population = assemblePopulation(samples, frequencies)
    print("{0:.1f}".format(interQuartileRange(len(population), population)))
