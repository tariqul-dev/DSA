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

int solve(TreeNode *root, int &result)
{
    if (!root)
        return 0;

    int left = solve(root->left, result);
    int right = solve(root->right, result);

    result = max(result, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;

    int result = INT_MIN;
    solve(root, result);

    return result;
}

int main()
{

    return 0;
}