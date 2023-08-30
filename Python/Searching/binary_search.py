def binSearch(ls, low, high, key):
    if low > high:
        return -1

    mid = (low + high) // 2

    if ls[mid] == key:
        return mid

    elif key < ls[mid]:
        return binSearch(ls, low, mid - 1, key)
    else:
        return binSearch(ls, mid + 1, high, key)


if __name__ == '__main__':
    nums = [-1, 0, 3, 5, 9, 12]
    target = 324
    ind = binSearch(nums, 0, len(nums) - 1, target)
    print(ind)
