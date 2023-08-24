#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void printPermutations(vector<int> &nums, vector<vector<int>> &result, int index = 0)
    {

        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);

            printPermutations(nums, result, index + 1);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> result;
        vector<int> temp;
        map<int, bool> helper;
        for (int i = 0; i < nums.size(); i++)
        {
            helper[nums[i]] = false;
        }

        printPermutations(nums, result);

        return result;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = Solution().permute(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}