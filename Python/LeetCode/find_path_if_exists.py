from collections import deque


def validPath(edges, source, destination):
    adjList = {}

    for u, v in edges:
        if u in adjList:
            adjList[u].append(v)
        else:
            adjList[u] = [v]
        if v in adjList:
            adjList[v].append(u)
        else:
            adjList[v] = [u]

    if source == destination:
        return True
    visited = [source]
    q = deque()
    q.append(source)

    while q:
        source = q.popleft()

        if source == destination:
            return True

        for node in adjList[source]:
            if node not in visited:
                visited.append(node)
                q.append(node)

    return False


if __name__ == '__main__':
    edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]]

    print(validPath(edges, 0, 5))
