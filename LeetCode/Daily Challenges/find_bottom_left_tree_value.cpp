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

// int findBottomLeftValue(TreeNode *root)
// {
//     queue<TreeNode *> q;

//     int bottomLeft = INT_MIN;
//     q.push(root);

//     while (!q.empty())
//     {
//         TreeNode *node = q.front();
//         q.pop();

//         bottomLeft = node->val;

//         if (node->right)
//             q.push(node->right);
//         if(node->left)
//             q.push(node->left);
//     }

//     return bottomLeft;
// }

int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> q;
    int bottomLeftElement = root->val;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            TreeNode *node = q.front();
            q.pop();

            bottomLeftElement = node->val;

            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
    }

    return bottomLeftElement;
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

    cout << findBottomLeftValue(root) << endl;

    return 0;
}