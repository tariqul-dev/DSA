#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;

    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

void insert(TreeNode *&root, int val)
{
    if (!root)
    {
        root = new TreeNode(val);
        return;
    }

    if (val < root->val)
        insert(root->left, val);
    else
        insert(root->right, val);
}

void print(TreeNode *root)
{
    if (root)
    {
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
        return p == q;

    return (p->val == q->val) && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main()
{
    TreeNode *root = NULL;
    TreeNode *root2 = NULL;

    insert(root, 1);
    insert(root, 2);
    insert(root, 3);

    insert(root2, 1);
    insert(root2, 2);
    insert(root2, 3);

    print(root);
    cout << endl;
    print(root2);
    cout << endl;

    cout << isSameTree(root, root2) << endl;

    return 0;
}