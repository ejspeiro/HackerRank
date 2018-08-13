if __name__ == "__main__":
    numSamples = int(input())
    samples = set(map(int, input().split()))
    numQueries = int(input())
    for query in range(numQueries):
        command = list(input().split())
        updatingSamples = set(map(int, input().split()))
        if command[0] == "intersection_update":
            samples.intersection_update(updatingSamples)
        elif command[0] == "update":
            samples.update(updatingSamples)
        elif command[0] == "symmetric_difference_update":
            samples.symmetric_difference_update(updatingSamples)
        elif command[0] == "difference_update":
            samples.difference_update(updatingSamples)
        else:
            pass
    print(sum(samples))
