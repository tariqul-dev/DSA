#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *right, *left;

    Node(int val)
    {
        this->val = val;
        right = left = NULL;
    }
};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }

    Node* createTree(int val)
    {
        // Node *newNode = new Node(val);

        if (!root){
            root = new Node(val);
            return;
        }

        if (val < root->val){
            root->left = createTree(val);
        }else {
            root->right = createTree(val);
        }

        return root;
    }
};

// TreeNode *invertTree(TreeNode *root)
// {
// }

int main()
{

    return 0;
}