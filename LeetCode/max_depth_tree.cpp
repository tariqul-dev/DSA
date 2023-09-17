#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode() {}

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

void print(TreeNode *root)
{
    if (root)
    {
        print(root->left);
        cout << root->val << " -> ";
        print(root->right);
    }
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;

    int leftMax = maxDepth(root->left);
    int righMax = maxDepth(root->right);

    return max(leftMax, righMax) + 1;
}

int main()
{

    TreeNode *t = new TreeNode(3);
    TreeNode *t1 = new TreeNode(9);
    TreeNode *t2 = new TreeNode(20);
    TreeNode *t3 = new TreeNode(15);
    TreeNode *t4 = new TreeNode(7);

    t->left = t1;
    t->right = t2;

    t2->left = t3;
    t2->right = t4;

    print(t);

    cout << endl;
    cout << maxDepth(t2) << endl;

    return 0;
}