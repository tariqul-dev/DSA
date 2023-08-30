if __name__ == '__main__':
    n = 10
    ls = []
    for i in range(n):
        temp = []
        for j in range(i + 1):
            if j == 0 or j == i:
                temp.append(1)
            else:
                temp.append(ls[i - 1][j - 1] + ls[i - 1][j])
        ls.append(temp)

    for row in range(len(ls)):
        for i in range(0, n - row):
            print(' ', end=' ')

        for col in range(len(ls[row])):
            print(ls[row][col], end='   ')

        print()
