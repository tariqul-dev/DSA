class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


class BinarySearchTree:
    def __init__(self, root=None):
        self.root = root

    def _insert(self, data, root):
        if not root:
            return Node(data)

        if data < root.data:
            root.left = self._insert(data, root.left)
        else:
            root.right = self._insert(data, root.right)

        return root

    def insert(self, data):
        self.root = self._insert(data, self.root)

    def _preOrder(self, root):
        if root:
            print(root.data, end=' ')
            self._preOrder(root.left)
            self._preOrder(root.right)

    def preOrder(self):
        self._preOrder(self.root)
        print()

    def _inOrder(self, root):
        if root:
            self._inOrder(root.left)
            print(root.data, end=' ')
            self._inOrder(root.right)

    def inOrder(self):
        self._inOrder(self.root)
        print()

    def _postOrder(self, root):
        if root:
            self._postOrder(root.left)
            self._postOrder(root.right)
            print(root.data, end=' ')

    def postOrder(self):
        self._postOrder(self.root)
        print()

    def _search(self, root, data, path=None):
        if not root:
            return None

        if path is None:
            path = []

        if data == root.data:
            path.append(root.data)
            return root

        if data < root.data:
            path.append(root.data)
            return self._search(root.left, data, path)
        else:
            path.append(root.data)
            return self._search(root.right, data, path)

    def search(self, data):
        path = []
        return self._search(self.root, data, path), path

    def _delete(self, root, key):
        if not root:
            return root

        if key < root.data:
            root.left = self._delete(root.left, key)
        elif key > root.data:
            root.right = self._


if __name__ == '__main__':
    bst = BinarySearchTree()

    bst.insert(8)
    bst.insert(3)
    bst.insert(10)
    bst.insert(1)
    bst.insert(6)
    bst.insert(4)
    bst.insert(7)
    bst.insert(14)
    bst.insert(13)

    bst.inOrder()

    bst.delete(6)

    bst.inOrder()
