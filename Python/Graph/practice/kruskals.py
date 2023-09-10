class DisjointSet:
    def __init__(self, v):
        self.parent = [0] * v
        self.rank = [0] * v

        for i in range(v):
            self.parent[i] = i
            self.rank[i] = 1

    def find(self, v):
        if v == self.parent[v]:
            return v

        self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u != v:

            if self.rank[u] < self.rank[v]:
                u, v = v, u

            self.parent[v] = u
            self.rank[u] += self.rank[v]


class Graph:
    def __init__(self, edges, numberOfVertex):
        self.numberOfVertex = numberOfVertex
        self.adjList = {}

        for u, v, w in edges:
            if u in self.adjList:
                self.adjList[u].append([v, w])
            else:
                self.adjList[u] = [[v, w]]
            if v in self.adjList:
                self.adjList[v].append([u, w])
            else:
                self.adjList[v] = [[u, w]]

    def kruskals(self, edges):
        sortedEdges = sorted(edges, key=lambda x: x[2])
        ds = DisjointSet(self.numberOfVertex)
        result = 0
        mst = []
        for u, v, w in sortedEdges:
            if ds.find(u) != ds.find(v):
                result += w
                mst.append([u, v, w])
                ds.union(u, v)

        return result, mst


def main():
    edges = [
        [0, 1, 28],
        [0, 5, 10],
        [1, 2, 16],
        [1, 6, 14],
        [2, 3, 12],
        [3, 4, 22],
        [3, 6, 18],
        [4, 6, 24],
        [4, 5, 25],
    ]
    numberOfVertex = 7
    graph = Graph(edges, numberOfVertex)
    result, mst = graph.kruskals(edges)

    print(result)
    print(mst)


if __name__ == '__main__':
    main()
