def merge(nums, low, mid, high):
    left = low
    right = mid + 1
    temp = []
    while left <= mid and right <= high:
        if nums[left] < nums[right]:
            temp.append(nums[left])
            left += 1
        else:
            temp.append(nums[right])
            right += 1

    while left <= mid:
        temp.append(nums[left])
        left += 1

    while right <= high:
        temp.append(nums[right])
        right += 1

    for i in range(low, high + 1):
        nums[i] = temp[i - low]


def mergeSort(nums, low, high):
    if low < high:
        mid = (low + high) // 2
        mergeSort(nums, low, mid)
        mergeSort(nums, mid + 1, high)
        merge(nums, low, mid, high)


def partition(nums, low, high):
    pivot = nums[low]
    i = low
    j = high

    while i < j:

        while i <= high - 1 and nums[i] <= pivot:
            i += 1

        while j >= low + 1 and nums[j] > pivot:
            j -= 1

        if i < j:
            nums[i], nums[j] = nums[j], nums[i]

    nums[low], nums[j] = nums[j], nums[low]
    return j


def quickSort(nums, low, high):
    if low < high:
        j = partition(nums, low, high)

        quickSort(nums, low, j - 1)
        quickSort(nums, j + 1, high)


def heapify(nums, n, current):
    largest = current
    lefChild = 2 * current + 1
    rightChild = 2 * current + 2

    if lefChild < n and nums[lefChild] > nums[largest]:
        largest = lefChild

    if rightChild < n and nums[rightChild] > nums[largest]:
        largest = rightChild

    if largest != current:
        nums[largest], nums[current] = nums[current], nums[largest],
        heapify(nums, n, largest)


def heapSort(nums, n):
    for i in range(n // 2 - 1, -1, -1):
        heapify(nums, n, i)

    for i in range(n - 1, -1, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heapify(nums, i, 0)


if __name__ == '__main__':
    nums = [5,2,3,1]
    print(nums)

    heapSort(nums, len(nums))

    print(nums)
