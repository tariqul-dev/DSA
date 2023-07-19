#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *left, *right;

    Node()
    {
        left = right = NULL;
    }

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void print(Node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int isBST(Node *root)
{
    if (root == NULL)
        return 1;

    static Node *prev = NULL;

    if (!isBST(root->left))
        return 0;

    if (prev != NULL && root->data <= prev->data)
        return 0;

    prev = root;

    return isBST(root->right);
}

Node *search(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node *searchForInsert(Node *root, int data)
{
    if (root == NULL)
        return NULL;

    static Node *prev = NULL;
    prev = root;

    if (root->data == data)
    {
        prev = NULL;
        return prev;
    }

    if (data < root->data)
        searchForInsert(root->left, data);

    else
        searchForInsert(root->right, data);

    return prev;
}

void insert(Node *root, int data)
{
    Node *prev = searchForInsert(root, data);
    Node *newNode = new Node(data);

    if (prev != NULL)
    {
        if (data < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
    }
}

int main()
{

    Node *n1 = new Node(6);

    // Node *n1 = new Node(5);
    // Node *n2 = new Node(3);
    // Node *n3 = new Node(6);
    // Node *n4 = new Node(1);
    // Node *n5 = new Node(4);

    // n1->left = n2;
    // n1->right = n3;

    // n2->left = n4;
    // n2->right = n5;

    print(n1);
    cout << endl;

    if (isBST(n1))
        cout << "This is BST" << endl;

    else
        cout << "This is not BST" << endl;

    int key = 5;

    if (search(n1, key))
        cout << "Found: " << key << endl;
    else
        cout << "Not Found: " << key << endl;

    insert(n1, 4);
    insert(n1, 9);
    insert(n1, 2);
    insert(n1, 3);
    insert(n1, 5);
    insert(n1, 10);
    insert(n1, 7);
    insert(n1, 12);

    cout << endl;

    print(n1);

    return 0;
}