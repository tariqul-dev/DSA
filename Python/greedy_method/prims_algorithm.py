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
        #                               weight, vertex
        heapq.heappush(minHeap, [0, source, source])
        # visited[source] = True
        res = 0
        mst = []
        cur = source

        while minHeap:
            weight, node, parent = heapq.heappop(minHeap)

            if not visited[node]:
                visited[node] = True
                if node != source:
                    res += weight
                    mst.append([parent, node, weight])

                # cur = node

                for neighbor, w in self.adjList[node]:
                    if not visited[neighbor]:
                        heapq.heappush(minHeap, [w, neighbor, node])

        print(res)
        print(mst)


if __name__ == '__main__':
    # edges = [
    #     [0, 1, 2],
    #     [0, 2, 1],
    #     [1, 2, 1],
    #     [2, 4, 2],
    #     [2, 3, 2],
    #     [3, 4, 1],
    # ]
    # v = 5
    # e = 6

    edges = [
        [0, 1, 2],
        [0, 3, 7],
        [0, 4, 6],
        [1, 2, 1],
        [1, 4, 4],
        [2, 3, 3],
        [2, 4, 2],
        [3, 4, 5],
    ]
    v = 5
    e = 8

    graph = Graph(edges, v, e)

    for p, c in graph.adjList.items():
        print(f'{p} -> {c}')

    graph.prims(0)

# output:
# [[0, 1, 2], [1, 2, 1], [2, 4, 2], [2, 3, 3]]
