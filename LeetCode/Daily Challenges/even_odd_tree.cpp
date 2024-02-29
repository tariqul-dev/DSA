#include <bits/stdc++.h>

using namespace std;

bool isEvenOddTree(TreeNode *root)
{
    queue<TreeNode *> q;

    q.push(root);

    bool isEvenLavel = true;

    while (!q.empty())
    {

        int n = q.size();
        int prev;

        if (isEvenLavel)
            prev = INT_MIN;
        else
            prev = INT_MAX;

        while (n--)
        {

            TreeNode *currNode = q.front();
            q.pop();

            if (isEvenLavel && (currNode->val % 2 == 0 || currNode->val <= prev))
            {
                return false;
            }

            if (!isEvenLavel && (currNode->val % 2 != 0 || currNode->val >= prev))
            {
                return false;
            }

            prev = currNode->val;

            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }

        isEvenLavel = !isEvenLavel;
    }

    return true;
}

int main()
{

    return 0;
}