import heapq
import sys


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

    def dijkastra(self, source, destination):
        inf = sys.maxsize
        costNode = {}

        for key in self.adjList.keys():
            costNode[key] = {'cost': inf, 'path': []}

        visited = []
        costNode[source]['cost'] = 0
        temp = source
        minHeap = []

        for i in range(self.numberOfVertex):
            if temp not in visited:
                visited.append(temp)

                minHeap = []
                for neighbor, weight in self.adjList[temp]:
                    if neighbor not in visited:

                        newCost = costNode[temp]['cost'] + weight
                        if costNode[neighbor]['cost'] > newCost:
                            costNode[neighbor]['cost'] = newCost
                            costNode[neighbor]['path'] = costNode[temp]['path'] + [temp]

                        heapq.heappush(minHeap, [costNode[neighbor]["cost"], neighbor])

            if minHeap:
                cost, temp = heapq.heappop(minHeap)

        for key, value in costNode.items():
            print(f'{key} -> {value}')

        return costNode[destination]['cost'], costNode[destination]['path'] + [destination],





def main():
    edges = [
        ['a', 'b', 2],
        ['a', 'c', 4],
        ['b', 'c', 3],
        ['b', 'd', 8],
        ['c', 'd', 2],
        ['c', 'e', 5],
        ['d', 'e', 11],
        ['d', 'f', 22],
        ['e', 'f', 1],
    ]

    graph = Graph(edges, 6)

    for key, value in graph.adjList.items():
        print(f'{key} -> {value}')

    cost, path = graph.dijkastra('a', 'd')

    print(cost)
    print(path)


if __name__ == '__main__':
    main()
