from bst import BST

if __name__ == '__main__':
    tree = BST()
    low = 6
    high = 10

    tree.insert(10)
    tree.insert(5)
    tree.insert(15)
    tree.insert(3)
    tree.insert(7)
    tree.insert(13)
    tree.insert(18)
    tree.insert(1)
    tree.insert(6)

    tree.printInOrder()

    sumOfNodes = tree.rangeSumBST(low, high)
    print('working')
    print(sumOfNodes)
