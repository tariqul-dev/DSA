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

void insert(Node *&root, int data)
{
    Node *newNode = new Node(data);

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Node *prev = searchForInsert(root, data);

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

    Node *root = NULL;

    // Node *n1 = new Node(5);
    // Node *n2 = new Node(3);
    // Node *n3 = new Node(6);
    // Node *n4 = new Node(1);
    // Node *n5 = new Node(4);

    // n1->left = n2;
    // n1->right = n3;

    // n2->left = n4;
    // n2->right = n5;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insert(root, data);
    }

    print(root);

    cout << endl;

    return 0;
}