from collections import deque


class Graph:
    def __init__(self, edges):
        self.adjList = {}

        for u, v in edges:
            if u in self.adjList:
                self.adjList[u].append(v)
            else:
                self.adjList[u] = [v]

            if v in self.adjList:
                self.adjList[v].append(u)
            else:
                self.adjList[v] = [u]

    def bfs(self, source):
        visited = [source]
        q = deque()
        q.append(source)

        while q:
            source = q.popleft()
            print(source, end=' ')

            for node in self.adjList[source]:
                if node not in visited:
                    visited.append(node)
                    q.append(node)

    def shortestPath(self, source, destination):
        visited = set()
        q = deque([(source, [source])])
        visited.add(source)

        while q:
            node, path = q.popleft()

            if node == destination:
                return path

            for neighbor in self.adjList[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    newPath = path + [neighbor]
                    q.append((neighbor, newPath))

        return []

    def minDistance(self, source, destination):

        if source not in self.adjList or destination not in self.adjList:
            return -1

        visited = set()
        q = deque([(source, 0)])
        visited.add(source)

        while q:
            node, distance = q.popleft()
            print(f'node: {node} => {distance}')

            if node == destination:
                return distance

            for neighbor in self.adjList[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    q.append((neighbor, distance + 1))

        return -1

    def _connectedComponents(self, source, visited=None):
        if visited is None:
            visited = set()

        visited.add(source)
        q = deque()
        q.append(source)

        while q:
            source = q.popleft()
            print(source, end=' ')

            for neighbor in self.adjList[source]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    q.append(neighbor)
        print()

    def connectedComponents(self, source):
        visited = set()
        visited.add(source)
        component = 1
        self._connectedComponents(source, visited)

        for key, value in self.adjList.items():
            if key not in visited:
                component += 1
                self._connectedComponents(key, visited)

        return component


if __name__ == '__main__':
    edges = [
        [1, 2],
        [1, 3],
        [1, 5],

        [2, 5],
        [3, 4],
        [4, 5],
        [4, 6],
        [5, 6],
        [7, 9],
        [10, 12],
    ]

    graph = Graph(edges)

    for parent, child in graph.adjList.items():
        print(f'{parent} => {child}')

    print()

    # graph.bfs(1)
    # print()
    # print(graph.minDistance(1, 6))
    print(graph.connectedComponents(1))
