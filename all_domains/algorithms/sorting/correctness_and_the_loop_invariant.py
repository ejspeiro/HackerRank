def insertion_sort(l):
    for i in range(1, len(l)):
        j = i
        while (j > 0) and (l[j] < l[j - 1]):
            key = l[j - 1]
            l[j - 1] = l[j]
            l[j] = key
            j -= 1


m = int(input().strip())
ar = [int(i) for i in input().strip().split()]
insertion_sort(ar)
print(" ".join(map(str, ar)))
