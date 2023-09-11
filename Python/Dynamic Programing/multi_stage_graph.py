import sys


class MultiStageGraph:
    def __init__(self, edges, numberOfVertex, stage):
        self.stage = stage
        self.numberOfVertex = numberOfVertex
        self.adjMatrix = [[0 for _ in range(numberOfVertex)] for _ in range(numberOfVertex)]

        for u, v, w in edges:
            self.adjMatrix[u][v] = w

    def multiStage(self):
        cost = [0] * self.numberOfVertex
        d = [0] * self.numberOfVertex
        n = self.numberOfVertex - 1
        path = [0] * (self.stage + 1)
        cost[n] = 0

        for i in range(n, -1, -1):
            minValue = sys.maxsize

            for j in range(i + 1, n + 1):

                if self.adjMatrix[i][j] != 0 and self.adjMatrix[i][j] + cost[j] < minValue:
                    minValue = self.adjMatrix[i][j] + cost[j]
                    d[i] = j
                    cost[i] = minValue

        path[1] = 1
        path[self.stage] = n
        for i in range(2, self.stage):
            path[i] = d[path[i - 1]]

        print(f'final cost: {cost}')
        print(f'final distance: {d}')
        print(path)

        print()


def main():
    # edges = [
    #     [1, 2, 2],
    #     [1, 3, 1],
    #     [1, 4, 3],
    #     # stage 2
    #     [2, 5, 2],
    #     [2, 6, 3],
    #
    #     [3, 5, 6],
    #     [3, 6, 7],
    #
    #     [4, 5, 6],
    #     [4, 6, 8],
    #     [4, 7, 9],
    #     # stage 3
    #     [5, 8, 6],
    #     [6, 8, 4],
    #     [7, 8, 5],
    # ]

    # numberOfVertex = 8
    # stage = 5
    edges = [
        # stage 1
        [1, 2, 9],
        [1, 3, 7],
        [1, 4, 3],
        [1, 5, 2],
        # stage 2
        [2, 6, 4],
        [2, 7, 2],
        [2, 8, 1],

        [3, 6, 2],
        [3, 7, 7],

        [4, 8, 11],

        [5, 7, 11],
        [5, 8, 8],
        # stage 3
        [6, 9, 6],
        [6, 10, 5],

        [7, 9, 4],
        [7, 10, 3],

        [8, 10, 5],
        [8, 11, 6],

        # stage 4
        [9, 12, 4],
        [10, 12, 2],
        [11, 12, 5],
    ]
    stage = 5
    numberOfVertex = 12

    graph = MultiStageGraph(edges, numberOfVertex + 1, stage)

    # for row in graph.adjMatrix:
    #     print(row)

    graph.multiStage()


if __name__ == '__main__':
    main()
