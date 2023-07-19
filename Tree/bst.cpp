
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

    cout << root->data << endl;
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

int main()
{

    Node *n1 = new Node(5);
    Node *n2 = new Node(7);
    Node *n3 = new Node(6);
    Node *n4 = new Node(1);
    Node *n5 = new Node(4);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    print(n1);

    cout << endl;
    cout << isBST(n1) << endl;

    return 0;
}