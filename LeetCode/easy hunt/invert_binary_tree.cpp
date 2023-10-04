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
        insert(root->left, val);
    else
        insert(root->right, val);
}

// TreeNode * invertNode(TreeNode *left, TreeNode right){

// }

TreeNode *invertTree(TreeNode *root)
{
    // if (!root)
    //     return NULL;

    // TreeNode *left = root->left;

    // root->left = invertTree(root->right);
    // root->right = invertTree(left);

    // return root;

    // Optimize with bfs
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *tree = q.front();
        q.pop();

        if (tree != NULL)
        {
            TreeNode *left = tree->left;
            tree->left = tree->right;
            tree->right = left;

            if (tree->left)
                q.push(tree->left);
            if (tree->right)
                q.push(tree->right);
        }
    }

    return root;
}

int main()
{
    TreeNode *root = NULL;

    insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 9);

    print(root);
    cout << endl;

    TreeNode *root2 = invertTree(root);

    print(root2);
    cout << endl;

    return 0;
}