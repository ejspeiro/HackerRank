from collections import Counter


if __name__ == "__main__":
    numGroupMembers = int(input())
    rooms = Counter(map(int, input().split()))
    for item, key in rooms.items():
        if key == 1:
            print(item)
            break
