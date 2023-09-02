class Item:
    def __init__(self, profit, weight):
        self.profit = profit
        self.weight = weight

    def __str__(self):
        return f'profit: {self.profit}\tweight: {self.weight}'


def knapsack(items, n, maxWeight):
    items = sorted(items, key=lambda item: item.profit / item.weight, reverse=True)

    profit = 0
    weight = 0

    for item in items:
        if weight + item.weight <= maxWeight:
            profit += item.profit
            weight += item.weight
        else:
            remain = maxWeight - weight
            profit += (item.profit/item.weight) * remain
            weight += remain

    # print(profit.__round__(2))
    return profit.__round__(2)


if __name__ == '__main__':
    items = [
        Item(10, 2),
        Item(5, 3),
        Item(15, 5),
        Item(7, 7),
        Item(6, 1),
        Item(18, 4),
        Item(3, 1),
    ]

    maxWeight = 15
    n = len(items)

    totalProfit = knapsack(items, n, maxWeight)

    print(totalProfit)
