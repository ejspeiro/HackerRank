if __name__ == "__main__":
    numSamples = int(input())
    samples = set(map(int, input().split()))
    numQueries = int(input())
    for query in range(numQueries):
        command = list(input().split())
        if command[0] == "pop":
            samples.pop()
        elif command[0] == "remove":
            samples.remove(int(command[1]))
        elif command[0] == "discard":
            samples.discard(int(command[1]))
        else:
            pass
    print(sum(samples))
