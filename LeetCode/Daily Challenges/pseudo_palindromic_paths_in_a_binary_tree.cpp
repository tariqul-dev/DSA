#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode *&root, vector<int> &freqCount, int &result)
{
    if (!root)
        return;

    freqCount[root->val]++;

    // left and right is null means this is leaf node
    if (!root->left && !root->right)
    {
        int oddFreq = 0;

        for (int i = 1; i < freqCount.size(); i++)
            if (freqCount[i] % 2 != 1)
                oddFreq++;

        if (oddFreq <= 1)
            result++;
    }

    solve(root->left, freqCount, result);
    solve(root->right, freqCount, result);

    freqCount[root->val]--;
}

int pseudoPalindromicPaths(TreeNode *root)
{
    vector<int> freqCount(10, 0);
    int result = 0;

    solve(root, freqCount, result);

    return result;
}

int main()
{
    TreeNode *root = NULL;

    root->val = 2;

    // TreeNode *

    return 0;
}