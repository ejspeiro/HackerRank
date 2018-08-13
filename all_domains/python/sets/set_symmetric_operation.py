if __name__ == "__main__":
    numSetA = int(input())
    setA = set(map(int, input().split()))
    numSetB = int(input())
    setB = set(map(int, input().split()))
    print(len(setA.symmetric_difference(setB)))
