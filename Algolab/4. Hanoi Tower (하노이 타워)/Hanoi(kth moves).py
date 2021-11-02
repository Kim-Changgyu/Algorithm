import sys

t = int(input())
for _ in range(t):
    n, k = map(int, sys.stdin.readline().split())

    arr = []
    for i in range(n-1, -1, -1):
        arr.append(k >> i & 1)
    
    x = 0
    for i in range(n-1, -1, -1):
        if arr[i] == 1:
            x = n-i
            break

    kMoves = (k >> x) + 1

    if n%2 == 1:
        if x%2 == 1:
            if kMoves%3 == 1:
                print("1 3")
            elif kMoves%3 == 2:
                print("3 2")
            else:
                print("2 1")
        else:
            if kMoves%3 == 1:
                print("1 2")
            elif kMoves%3 == 2:
                print("2 3")
            else:
                print("3 1")
    else:
        if x%2 == 1:
            if kMoves%3 == 1:
                print("1 2")
            elif kMoves%3 == 2:
                print("2 3")
            else:
                print("3 1")
        else:
            if kMoves%3 == 1:
                print("1 3")
            elif kMoves%3 == 2:
                print("3 2")
            else:
                print("2 1")
