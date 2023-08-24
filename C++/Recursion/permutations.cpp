#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void printPermutations(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, map<int, bool> &helper)
    {

        if (temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!helper[i])
            {
                temp.push_back(nums[i]);

                helper[i] = true;

                printPermutations(nums, result, temp, helper);

                temp.pop_back();
                helper[i] = false;
            }
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

        printPermutations(nums, result, temp, helper);

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