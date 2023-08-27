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

    def _search(self, root, key, path):
        if root is None:
            return None

        if root.data == key:
            path.append(root.data)
            print(root.data)
            print('found')
            return root, path

        if key < root.data:
            path.append(root.data)
            print(f'{root.data}', end='->')
            self._search(root.left, key, path)

        else:
            path.append(root.data)
            print(f'{root.data}', end='->')
            self._search(root.right, key, path)

        return root, path

    def search(self, key):
        path = []
        root, path = self._search(self.root, key, path)

        if root:
            print(f'{key} is found')
            print(f"{'->'.join([str(p) for p in path])}")
        else:
            print(f'{key} is not found')


if __name__ == '__main__':
    tree = Tree()

    tree.insert(6)
    tree.insert(4)
    tree.insert(8)
    tree.insert(3)
    tree.insert(2)
    tree.insert(1)
    tree.insert(7)
    tree.insert(10)
    tree.insert(11)

    tree.print_inorder()
    print()


    tree.search(11)
