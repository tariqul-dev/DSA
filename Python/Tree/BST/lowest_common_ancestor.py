from bst_insertion_traversel import Tree

if __name__ == '__main__':
    tree = Tree()
    # tree.insert(8)
    # tree.insert(4)
    # tree.insert(2)
    # tree.insert(1)
    # tree.insert(3)
    # tree.insert(6)
    # tree.insert(5)
    # tree.insert(7)
    # tree.insert(10)
    # tree.insert(14)
    # tree.insert(15)
    # tree.insert(9)
    # tree.insert(12)
    # tree.insert(11)
    # tree.insert(13)

    tree.insert(4)
    tree.insert(2)
    tree.insert(3)
    tree.insert(1)
    tree.insert(7)
    tree.insert(6)

    # n = int(input())
    # for i in range(n):
    #     tree.insert(int(input().strip()))
    #
    tree.print_inorder()

    ans = tree.lca(1, 9)
    print()

    print(ans.data)

