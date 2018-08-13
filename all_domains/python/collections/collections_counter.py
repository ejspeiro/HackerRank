from collections import Counter

if __name__ == "__main__":
    numSizes = int(input())
    listSizes = list(map(int, input().split()))
    numCustomers = int(input())
    shoeSizeCount = Counter(listSizes)
    totalCustomers = 0
    for customer in range(numCustomers):
        sizeBougth, purchaseTotal = map(int, input().split())
        if shoeSizeCount[sizeBougth] > 0:
            totalCustomers += purchaseTotal
            shoeSizeCount[sizeBougth] = shoeSizeCount[sizeBougth] - 1
    print(totalCustomers)
