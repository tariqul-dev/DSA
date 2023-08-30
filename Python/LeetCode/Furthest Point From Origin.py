def furthestDistanceFromOrigin(moves: str):
    strLen = len(moves)
    lCount = 0
    rCount = 0

    for move in moves:
        if move == 'L':
            lCount += 1
        elif move == 'R':
            rCount += 1

    emptyCount = strLen - (lCount + rCount)

    return abs(lCount - rCount) + emptyCount

    print(lCount)
    print(rCount)
    print(ans)


if __name__ == '__main__':
    moves = "_______"

    farAway = furthestDistanceFromOrigin(moves)
    print(farAway)
