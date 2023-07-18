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

void printPreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    printPreOrder(root->left);

    printPreOrder(root->right);
}

void printPostcOrder(Node *root)
{
    if (root == NULL)
        return;

    printPostcOrder(root->left);
    printPostcOrder(root->right);

    cout << root->data << " ";
}

void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    printPreOrder(n1);
    cout << endl;
    printPostcOrder(n1);
    cout << endl;
    printInOrder(n1);

    return 0;
}