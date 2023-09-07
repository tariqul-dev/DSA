class Graph:
    def __init__(self, vertex, edges):
        self.vertex = vertex
        self.adjList = {}

        for u, v in edges:
            if u in self.adjList:
                self.adjList[u].append(v)
            else:
                self.adjList[u] = [v]

    def dfs(self, source, visited=None, recStack=None):
        if visited is None:
            visited = [False] * self.vertex

        if recStack is None:
            recStack = [False] * self.vertex

        visited[source] = True
        recStack[source] = True

        if source in self.adjList:

            for neighbor in self.adjList[source]:
                if not visited[neighbor]:
                    isDone = self.dfs(neighbor, visited, recStack)
                    if isDone:
                        return True
                elif recStack[neighbor]:
                    return True

            recStack[source] = False
        return False

    def isCyclic(self, source):
        visited = [False] * vertex

        parent = self.dfs(source, visited)

        for node in self.adjList.keys():
            if node != source:
                return self.dfs(node, visited)

        return parent


if __name__ == '__main__':
    vertex = 5
    edge = [
        [0, 1],
        [2, 1],
        [2, 3],
        [3, 4],
        [4, 2],
    ]

    graph = Graph(vertex, edge)

    print(graph.isCyclic(0))

# 0 --> 1 <-- 2
#           /  ^\
#          3 -> 4
