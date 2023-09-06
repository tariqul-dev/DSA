from collections import deque


def bfs(graph, src, n):
    visited = set()
    visited.add(src)
    dist = [-1] * n

    dist[src] = 0

    q = deque()
    q.append(src)

    while q:
        node = q.popleft()
        print(node, end=' ')

        for i in range(n):
            if graph[node][i] == 1 and i not in visited:
                dist[i] = dist[node] + 1
                q.append(i)
                visited.add(i)

    print()
    print(dist)


if __name__ == '__main__':
    n = 5
    maze = [[0] * n for _ in range(n)]
    edges = [
        [0, 1],
        [0, 2],
        [2, 1],
        [2, 3],
        [2, 4],
        [3, 1],
        [3, 4],
        [4, 1],
    ]

    for vertex in edges:
        src, des = vertex
        maze[src][des] = 1
        maze[des][src] = 1

    for m in maze:
        print(m)

    print()
    bfs(maze, 0, n)

# 5
# 0 1 1 0 0
# 1 0 1 1 1
# 1 1 0 1 1
# 0 1 1 0 1
# 0 1 1 1 0

# 0 --- 1
# |    /| \
# |  /  |  4
# |/    |   \
# 2---- 3   \
# |________/
