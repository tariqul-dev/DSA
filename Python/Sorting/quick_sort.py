def partition(a, low, high):
    pivot = a[low]
    i = low
    j = high

    while i < j:
        while i <= high - 1 and a[i] <= pivot:
            i += 1
        while j >= low + 1 and a[j] > pivot:
            j -= 1

        if i < j:
            a[i], a[j] = a[j], a[i]

    a[low], a[j] = a[j], a[low]
    return j


def quickSort(a, low, high):
    if low < high:
        j = partition(a, low, high)
        quickSort(a, low, j - 1)
        quickSort(a, j + 1, high)


if __name__ == '__main__':
    a = [10, 16, 8, 12, 15, 6, 3, 9, 5]

    print(a)

    quickSort(a, 0, len(a) - 1)

    print(a)
