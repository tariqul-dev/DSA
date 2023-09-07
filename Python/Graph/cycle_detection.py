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

    def dfs(self, source, parent=-1, visited=None):
        if visited is None:
            visited = [False] * len(self.adjList)

        visited[source] = True

        for neighbor in self.adjList[source]:
            if not visited[neighbor]:
                isDone = self.dfs(source=neighbor, parent=source, visited=visited)
                if isDone:
                    return True

            elif parent != neighbor:
                return True

        return False

    def cycleDetection(self, source):
        visited = [False] * len(self.adjList)
        visited[source] = True

        if self.dfs(source, parent=-1, visited=visited):
            return True

        for node in self.adjList.keys():
            if node != source and not visited[node]:
                return self.dfs(node, parent=-1, visited=visited)

        return False


if __name__ == '__main__':
    edges = [
        [0, 1],
        [0, 3],
        [3, 2],
        # [3, 4],
        [2, 4],

        [5, 6],
        [6, 7],
        [7, 5]
    ]

    graph = Graph(edges)

    print(graph.adjList)

    print(graph.cycleDetection(0))

    #    1
    #  /
    # 0
    #  \
    #    3 ---- 2
    #     \   /
    #       4
    #
    # 5 ------ 6
    #  \      /
    #   \    /
    #     7
