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

void print(TreeNode *root)
{
    if (root)
    {
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
}

void insert(TreeNode *&root, int val)
{
    if (!root)
    {
        root = new TreeNode(val);
        return;
    }

    if (val < root->val)
    {
        insert(root->left, val);
    }
    else
        insert(root->right, val);
}

void rangeSum(TreeNode *&root, int low, int high, int &sum)
{
    if (!root)
        return;

    if (root->val >= low && root->val <= high)
        sum += root->val;

    rangeSum(root->left, low, high, sum);
    rangeSum(root->right, low, high, sum);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int sum = 0;
    rangeSum(root, low, high, sum);

    return sum;
}

int main()
{
    int low = 7, high = 15;

    TreeNode *root = NULL;

    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);

    print(root);

    cout << endl;

    cout << rangeSumBST(root, low, high);

    return 0;
}