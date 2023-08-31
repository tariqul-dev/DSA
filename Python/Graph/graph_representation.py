class Graph:
    def __init__(self, edges):
        self.graph = {}

        for (u, v) in edges:
            if u in self.graph:
                self.graph[u].append(v)
            else:
                self.graph[u] = [v]



if __name__ == '__main__':
    edges = [
        (1, 2),
        (1, 3),
        (2, 1),
        (2, 4),
        (2, 5),
        (3, 1),
        (3, 4),
        (3, 6),
        (4, 2),
        (4, 3),
        (4, 5),
        (4, 6),
        (5, 2),
        (5, 4),
        (5, 6),
        (6, 3),
        (6, 4),
        (6, 5),
    ]

    graph = Graph(edges)

    print(graph.graph)
