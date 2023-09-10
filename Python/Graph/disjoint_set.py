def make(v, parent, size):
    parent[v] = v
    size[v] = 1


def find(v, parent):
    if v == parent[v]:
        return v
    parent[v] = find(parent[v], parent)
    return parent[v]


def union(a, b, parent, size):
    print(f'actual: ({a}, {b})')
    a = find(a, parent)
    b = find(b, parent)

    print(f'parent pair: ({a}, {b})')

    if a != b:
        if size[a] < size[b]:
            a, b = b, a
        parent[b] = a
        size[a] += size[b]


if __name__ == '__main__':
    u = [0, 1, 2, 3, 4, 5, 6, 7]
    size = [0] * len(u)
    parent = [0] * len(u)

    for i in range(len(u)):
        make(i, parent, size)

    print(parent)

    union(0, 1, parent, size)

    print(parent)

    union(2, 3, parent, size)

    print(parent)

    union(4, 5, parent, size)

    print(parent)

    union(6, 7, parent, size)

    print(parent)

    union(1, 3, parent, size)
    print(parent)

    union(3, 4, parent, size)
    print(parent)

    union(2, 6, parent, size)
    print(parent)

    # print(find(5, parent))
    # print(parent)
    #
    # print(find(7, parent))
    # print(parent)
    #
    # print(find(3, parent))
    # print(parent)
    #
    # print(find(7, parent))


