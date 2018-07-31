# -*- coding: utf8 -*-


def weightedMean(numSamples, samples, weights):
    return sum([product[0]*product[1] for
                product in zip(samples, weights)])/sum(weights)


if __name__ == '__main__':
    numSamples = int(input())
    samples = list(map(int, input().split()))
    weights = list(map(int, input().split()))
    print("{0:.1f}".format(weightedMean(numSamples, samples, weights)))
