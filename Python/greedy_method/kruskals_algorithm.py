class DisjointSet:
    def __init__(self, vertex):
        self.parent = [0] * vertex
        self.size = [0] * vertex

        for i in range(vertex):
            self.parent[i] = i
            self.size[i] = 1

    def find(self, v):
        if v == self.parent[v]:
            return v
        self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u != v:
            if self.size[u] < self.size[v]:
                u, v = v, u

            self.parent[v] = u
            self.size[u] += self.size[v]


class Graph:
    def __init__(self, edges, numberOfVertex, numberOfEdges):
        self.adjList = {}
        self.numberOfVertex = numberOfVertex
        self.numberOfEdges = numberOfEdges

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
        print(sortedEdges)
        result = 0
        mst = []
        for u, v, w in sortedEdges:
            if ds.find(u) != ds.find(v):
                result += w
                mst.append([u, v, w])
                ds.union(u, v)

        print(result)
        print(mst)


def main():
    edge = [
        [0, 1, 2],
        [0, 3, 7],
        [0, 4, 6],
        [1, 2, 1],
        [1, 4, 4],
        [2, 3, 3],
        [2, 4, 2],
        [3, 4, 5],
    ]
    nVertex = 5
    nEdge = 8

    graph = Graph(edge, nVertex, nEdge)

    for key, value in graph.adjList.items():
        print(f'{key} -> {value}')

    print()

    graph.kruskals(edge)


if __name__ == '__main__':
    main()
