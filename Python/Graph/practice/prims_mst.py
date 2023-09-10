import heapq


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

    def prims(self, source):
        visited = [False] * self.numberOfVertex
        minHeap = []
        heapq.heappush(minHeap, [0, source, source])  # weight child parent
        result = 0
        mst = []

        while minHeap:
            weight, node, parent = heapq.heappop(minHeap)

            if not visited[node]:
                visited[node] = True
                if node != source:
                    result += weight
                    mst.append([parent, node, weight])

                for neighbor, w, in self.adjList[node]:
                    if not visited[neighbor]:
                        heapq.heappush(minHeap, [w, neighbor, node])

        return result, mst


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

    vertex = 5
    nEdge = 8

    graph = Graph(edge, vertex, nEdge)

    for key, value in graph.adjList.items():
        print(f'{key} -> {value}')

    result, mst = graph.prims(0)

    print(result)

    print(mst)


if __name__ == '__main__':
    main()
