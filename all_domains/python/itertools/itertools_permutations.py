from itertools import permutations

if __name__ == '__main__':
    theString, maxSize = input().split()
    maxSize = int(maxSize)
    permutationsTheString = list(permutations(theString, maxSize))
    listPermutation = list()
    for permutation in permutationsTheString:
        permutationAsString = ""
        for element in permutation:
            permutationAsString += element
        listPermutation.append(permutationAsString)
    listPermutation = sorted(listPermutation)
    for permutation in listPermutation:
        print(permutation)
