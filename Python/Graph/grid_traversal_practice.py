from collections import deque


class GridGraph:
    def __init__(self, row, col, ):
        self.row = row
        self.col = col
        self.maze = [[0 for _ in range(col)] for _ in range(row)]
        self.source = []
        self.destination = []

        for i in range(row):
            rowStr = input().strip()
            for j in range(col):
                if rowStr[j] == '#':
                    self.maze[i][j] = -1

                if rowStr[j] == 'A':
                    self.source = [i, j]

                if rowStr[j] == 'B':
                    self.destination = [i, j]

    def inSideMaze(self, coord):
        x, y = coord
        return 0 <= x < self.row and 0 <= y < self.col

    def isSave(self, coord):
        x, y = coord
        return self.maze[x][y] != -1

    def isVisited(self, visited, coord):
        return coord in visited

    def bfs(self):
        dx = [0, 0, -1, 1]
        dy = [1, -1, 0, 0]

        visited = [self.source]

        q = deque([(self.source, [self.source],)])

        while q:
            node, path = q.popleft()
            x, y = node

            if node == self.destination:
                return path

            for i in range(0, 4):
                newX = x + dx[i]
                newY = y + dy[i]

                newNode = [newX, newY]

                if self.inSideMaze(newNode) and self.isSave(newNode) and not self.isVisited(visited, newNode):
                    newPath = path + [newNode]
                    q.append((newNode, newPath))
                    visited.append(newNode)

        return None

    def walkInMaze(self):
        path = self.bfs()
        print(path)

        if path:
            direction = ''

            for i in range(1, len(path)):
                prevX, prevY = path[i - 1]
                curX, curY = path[i]

                # left
                if prevX == curX and prevY > curY:
                    direction = 'Left'
                elif prevX < curX and prevY == curY:
                    direction = 'Down'
                elif prevX == curX and prevY < curY:
                    direction = 'Right'
                elif prevX > curX and prevY == curY:
                    direction = 'Up'

                print(direction, end=' ')
        else:
            print('No Path found')


if __name__ == '__main__':
    row, col = map(int, input().strip().split())
    graph = GridGraph(row, col)

    for maze in graph.maze:
        for i in maze:
            print(i, end='\t')
        print()

    graph.walkInMaze()

"""
5 8
########
#.A#...#
#.##.#B#
#......#
########
"""
