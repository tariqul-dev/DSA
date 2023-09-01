def heapify(nums, n, current):
    largest = current
    leftChild = 2 * current + 1
    rightChild = 2 * current + 2

    if leftChild < n and nums[leftChild] > nums[largest]:
        largest = leftChild

    if rightChild < n and nums[rightChild] > nums[largest]:
        largest = rightChild

    if largest != current:
        nums[largest], nums[current] = nums[current], nums[largest]
        heapify(nums, n, largest)


def heapSort(nums):
    length = len(nums)
    for i in range(length - 1, -1, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heapify(nums, i, 0)


if __name__ == '__main__':
    a = [10, 20, 15, 12, 40, 25, 18]
    n = len(a)

    for i in range((n // 2) - 1, -1, -1):
        heapify(a, n, i)

    print(a)

    heapSort(a)

    print(a)
