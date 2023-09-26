#include <bits/stdc++.h>

using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

class Tree
{
public:
    TreeNode *root;

    Tree()
    {
        root = NULL;
    }
};

void print(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }
}

bool symetricCheck(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->val != right->val)
        return false;

    return symetricCheck(left->left, right->right) && symetricCheck(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL || symetricCheck(root->left, root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);

    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);

    TreeNode *rn2 = new TreeNode(2);
    TreeNode *rn3 = new TreeNode(3);
    TreeNode *rn4 = new TreeNode(4);

    root->left = n2;
    n2->left = n3;
    n2->right = n4;

    root->right = rn2;
    rn2->left = rn4;
    // rn2->right = rn3;

    print(root);
    cout << endl;

    cout << isSymmetric(root) << endl;

    return 0;
}