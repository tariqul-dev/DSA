from collections import deque


def inSideMaze(coord, n, m):
    x, y = coord
    return x in range(0, n) and y in range(0, m)


def isSafe(maze, coord):
    x, y = coord
    return maze[x][y] != -1


def isVisited(visited, coord):
    return coord in visited


def bfs(maze, source, des, n, m):
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    visited = [source]

    q = deque([(source, [])])

    while q:
        node, path = q.popleft()
        x, y = node

        if node == des:
            return path

        for i in range(4):
            newX = x + dx[i]
            newY = y + dy[i]
            newNode = [newX, newY]

            if inSideMaze(newNode, n, m) and isSafe(maze, newNode) and not isVisited(visited, newNode):
                newPath = path + [newNode]
                q.append((newNode, newPath))
                visited.append(newNode)

    return []


if __name__ == '__main__':
    n, m = map(int, input().strip().split())

    maze = [[0 for _ in range(m)] for _ in range(n)]
    source = ()
    des = ()

    for i in range(n):
        rowStr = input().strip()
        for j in range(m):
            if rowStr[j] == '#':
                maze[i][j] = -1
            if rowStr[j] == 'A':
                source = [i, j]
            if rowStr[j] == 'B':
                des = [i, j]

    for i in maze:
        print(i)

    path = bfs(maze, source, des, n, m)

    print(path)
    print(len(path))

"""
5 8
########
#.A#...#
#.##.#B#
#......#
########
"""
