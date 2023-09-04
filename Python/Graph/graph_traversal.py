from collections import deque


class Graph:
    def __init__(self, edges):
        self.adjList = {}

        for u, v in edges:
            if u in self.adjList:
                self.adjList[u].append(v)
            else:
                self.adjList[u] = [v]

    def bfs(self, source):
        q = deque()
        visited = [source]
        q.append(source)

        while q:
            node = q.popleft()
            print(node, end=' ')

            for adjNode in self.adjList[node]:
                if adjNode not in visited:
                    visited.append(adjNode)
                    q.append(adjNode)

    def dfs(self, source, visited=None):
        if visited is None:
            visited = []

        print(source, end=' ')

        visited.append(source)

        for node in self.adjList[source]:
            if node not in visited:
                self.dfs(node, visited)


if __name__ == '__main__':
    edges = [
        (1, 2),
        (1, 3),
        (1, 5),
        (1, 6),
        (2, 1),
        (2, 3),
        (2, 4),
        (2, 5),
        (3, 1),
        (3, 2),
        (3, 4),
        (3, 6),
        (4, 2),
        (4, 3),
        (4, 5),
        (5, 1),
        (5, 2),
        (5, 4),
        (6, 1),
        (6, 3),
    ]

    graph = Graph(edges)

    graph.bfs(1)
    print()
    graph.dfs(1)
