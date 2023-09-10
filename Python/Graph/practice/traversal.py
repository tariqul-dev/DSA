from collections import deque


class Graph:
    def __init__(self, edges, numberOfVertex, numberOfEdge):
        self.adjList = {}
        self.numberOfVertex = numberOfVertex
        self.numberOfEdge = numberOfEdge

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
        visited = [False] * self.numberOfVertex
        q = deque()
        q.append(source)
        visited[source] = True

        while q:
            node = q.popleft()
            print(node, end=' -> ')

            for neighbor in self.adjList[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    q.append(neighbor)

        print()

    def dfs(self, source, visited=None):

        if visited is None:
            visited = [False] * self.numberOfVertex
        print(source, end=' -> ')

        visited[source] = True

        for neighbor in self.adjList[source]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited)

    def shortestPath(self, source, destination):
        visited = [False] * self.numberOfVertex
        q = deque([(source, [source])])
        visited[source] = True
        while q:
            node, path = q.popleft()
            if node == destination:
                return path

            for neighbor in self.adjList[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    newPath = path + [neighbor]
                    q.append((neighbor, newPath))

        return None

    def cycleDetection(self, source, visited=None, parent=None):
        if visited is None:
            visited = [False] * self.numberOfVertex

        visited[source] = True

        for neighbor in self.adjList[source]:
            if not visited[neighbor]:
                if self.cycleDetection(neighbor, visited, source):
                    return True
            elif parent != neighbor:
                return True

        return False


if __name__ == '__main__':
    # edges = [
    #     [0, 1],
    #     [0, 2],
    #     [0, 4],
    #     [1, 4],
    #     [2, 3],
    #     [3, 4],
    #     [3, 5],
    #     [4, 5],
    # ]

    edges = [
        [0, 1],
        # [1, 2],
        [1, 3],
        [2, 3],
    ]
    numberOfVertex = 4
    numberOfEdge = len(edges)

    graph = Graph(edges, numberOfVertex, numberOfEdge)

    for key, value in graph.adjList.items():
        print(f'{key} -> {value}')

    graph.bfs(0)
    graph.dfs(0)
    print()

    path = graph.shortestPath(0, 3)
    print(path)

    res = graph.cycleDetection(0)
    print(res)
