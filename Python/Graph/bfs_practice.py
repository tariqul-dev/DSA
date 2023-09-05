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
        q.append(source)
        visited = [source]

        while q:
            current = q.popleft()
            print(current, end=' ')

            for node in self.adjList[current]:
                if node not in visited:
                    visited.append(node)
                    q.append(node)

    def dfs(self, source, visited=None):
        if visited is None:
            visited = []
        visited.append(source)
        print(source, end=' ')

        for node in self.adjList[source]:
            if node not in visited:
                self.dfs(node, visited)


if __name__ == '__main__':
    edges = [
        (1, 2),
        (1, 3),
        (2, 1),
        (2, 4),
        (2, 5),
        (3, 1),
        (3, 4),
        (3, 6),
        (4, 2),
        (4, 3),
        (4, 5),
        (4, 6),
        (5, 2),
        (5, 4),
        (5, 6),
        (6, 3),
        (6, 4),
        (6, 5),
    ]

    graph = Graph(edges)
    print(graph.adjList)

    graph.bfs(1)
    print()
    graph.dfs(1)
