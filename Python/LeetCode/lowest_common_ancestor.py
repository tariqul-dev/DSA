from bst import BST

if __name__ == '__main__':
    tree = BST()
    tree.insert(6)
    tree.insert(2)
    tree.insert(8)
    tree.insert(0)
    tree.insert(4)
    tree.insert(3)
    tree.insert(5)
    tree.insert(7)
    tree.insert(9)

    tree.printInOrder()
    print()
    parent = tree.lca(2, 8)

    print(parent)
