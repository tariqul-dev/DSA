def merge(numbers, low, mid, high):
    left = low
    right = mid + 1
    temp = []

    while left <= mid and right <= high:
        if numbers[left] < numbers[right]:
            temp.append(numbers[left])
            left += 1
        else:
            temp.append(numbers[right])
            right += 1

    while left <= mid:
        temp.append(numbers[left])
        left += 1

    while right <= high:
        temp.append(numbers[right])
        right += 1

    for i in range(low, high + 1):
        numbers[i] = temp[i - low]


def mergeSort(numbers, low, high):
    if low < high:
        mid = (low + high) // 2

        mergeSort(numbers, low, mid)
        mergeSort(numbers, mid + 1, high)
        merge(numbers, low, mid, high)


if __name__ == '__main__':
    nums = [9, 3, 7, 5, 6, 4, 8, 2]

    mergeSort(nums, 0, len(nums) - 1)
    print(nums)
