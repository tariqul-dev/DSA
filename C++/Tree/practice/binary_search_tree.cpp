#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node() {}

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    void _printInOrder(Node *root)
    {
        if (root)
        {
            _printInOrder(root->left);
            cout << root->data << " ";
            _printInOrder(root->right);
        }
    }

    void printInOrder(Node *root = NULL)
    {
        if (!root)
        {
            root = this->root;
        }
        _printInOrder(root);
        cout << endl;
    }

    Node *_insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }

        if (data < root->data)
            root->left = _insert(root->left, data);

        else
            root->right = _insert(root->right, data);

        return root;
    }

    void insert(int data)
    {
        root = _insert(root, data);
    }

    Node *findAncestor(Node *root)
    {
        if (!root->left)
            return root;

        return findAncestor(root->left);
    }

    Node *_deleteNode(Node *root, int key)
    {
        if (!root)
            return root;

        if (key < root->data)
            root->left = _deleteNode(root->left, key);

        else if (key > root->data)
            root->right = _deleteNode(root->right, key);

        else
        {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            Node *temp = findAncestor(root->right);
            root->data = temp->data;

            root->right = _deleteNode(root->right, root->data);

            delete temp;
        }

        return root;
    }
    void deleteNode(int key)
    {
        root = _deleteNode(root, key);
    }

    Node *_lca(Node *root, int u, int v)
    {
        if (!root)
            return root;
        if (root->data == u || root->data == v)
            return root;
        
        Node *left = _lca(root->left, u, v);
        Node *right = _lca(root->right, u, v);

        if (!left)
            return right;

        if (!right)
            return left;

        return root;
    }

    void lca(int u, int v)
    {

        Node *parent = _lca(root, u, v);

        cout << parent->data << endl;
    }
};

int main()
{
    BST tree = BST();

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    tree.insert(2);

    // tree.printInOrder();


    tree.printInOrder();

    tree.lca(4, 2);

    return 0;
}