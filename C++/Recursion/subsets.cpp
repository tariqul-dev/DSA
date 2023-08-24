#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void findSubsets(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int index = 0)
    {
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        output.push_back(nums[index]);

        findSubsets(nums, ans, output, index + 1);

        output.pop_back();

        findSubsets(nums, ans, output, index + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> output;

        findSubsets(nums, ans, output);
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};

    Solution s = Solution();
    vector<vector<int>> ans = s.subsets(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}