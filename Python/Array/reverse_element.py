def reverseArray(a):
    i = 0
    j = len(a) - 1
    _reverse_element(a, i, j)

    return a


def _reverse_element(a, i, j):
    if i >= j:
        return

    a[i], a[j] = a[j], a[i]
    _reverse_element(a, i + 1, j - 1)


if __name__ == '__main__':
    ls = [1, 2, 3]
    reverseArray(ls)

    print(ls)
