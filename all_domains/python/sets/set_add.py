if __name__ == "__main__":
    numSamples = int(input())
    stamps = set()
    for query in range(numSamples):
        stamp = str(input())
        stamps.add(stamp)
    print(len(stamps))
