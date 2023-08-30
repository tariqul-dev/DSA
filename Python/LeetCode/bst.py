class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BST:
    def __init__(self):
        self.root = None

    def _insert(self, root, val):
        if not root:
            return Node(val)

        if val < root.val:
            root.left = self._insert(root.left, val)
        else:
            root.right = self._insert(root.right, val)

        return root

    def insert(self, val):
        self.root = self._insert(self.root, val)

    def _printPreOrder(self, root):
        if root:
            print(root.val, end=' ')
            self._printPreOrder(root.left)
            self._printPreOrder(root.right)

    def _printInOrder(self, root):
        if root:
            self._printInOrder(root.left)
            print(root.val, end=' ')
            self._printInOrder(root.right)

    def _printPostOrder(self, root):
        if root:
            self._printPostOrder(root.left)
            self._printPostOrder(root.right)
            print(root.val, end=' ')

    def printPreOrder(self):
        self._printPreOrder(self.root)

    def printInOrder(self):
        self._printInOrder(self.root)

    def printPostOrder(self):
        self._printPostOrder(self.root)

    def _lca(self, root, p, q):
        if not root:
            return root

        if root.val == p or root.val == q:
            return root

        left = self._lca(root.left, p, q)
        right = self._lca(root.right, p, q)

        if not left:
            return right
        if not right:
            return left

        return root

    def lca(self, p, q):
        root = self._lca(self.root, p, q)

        if root:
            return root.val
        return None
