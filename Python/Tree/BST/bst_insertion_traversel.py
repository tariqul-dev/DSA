class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def _insert(self, node, data):
        if not node:
            return Node(data)

        if data < node.data:
            node.left = self._insert(node.left, data)
        else:
            node.right = self._insert(node.right, data)

        return node

    def insert(self, data):
        if not self.root:
            self.root = Node(data)
            return

        self.root = self._insert(self.root, data)

    def _print_inorder(self, node):
        if node:
            self._print_inorder(node.left)
            print(node.data, end=' ')
            self._print_inorder(node.right)

    def print_inorder(self):
        self._print_inorder(self.root)

    def _print_preorder(self, node):
        if node:
            print(node.data, end=' ')
            self._print_preorder(node.left)
            self._print_preorder(node.right)

    def print_preorder(self):
        self._print_preorder(self.root)

    def _print_post_order(self, node):
        if node:
            self._print_post_order(node.left)
            self._print_post_order(node.right)
            print(node.data, end=' ')

    def print_post_order(self):
        self._print_post_order(self.root)

    def _lca(self, root, v1, v2):
        if not root:
            return root

        if root.data == v1 or root.data == v2:
            return root

        left = self._lca(root.left, v1, v2)
        right = self._lca(root.right, v1, v2)

        if left is None:
            return right
        if right is None:
            return left

        return root

    def lca(self, n1, n2):
        return self._lca(self.root, n1, n2)


if __name__ == '__main__':
    tree = Tree()

    tree.insert(5)
    tree.insert(7)
    tree.insert(2)

    tree.print_inorder()
    print()
    tree.print_preorder()
    print()
    tree.print_post_order()
