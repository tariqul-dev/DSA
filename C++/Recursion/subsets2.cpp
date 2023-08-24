#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void findSubset(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, int index = 0)
    {

        result.push_back(temp);

        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            findSubset(nums, result, temp, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;
        findSubset(nums, result, temp);

        return result;
    }
};

int main()
{
    vector<int> arr = {1, 2, 2};

    vector<vector<int>> result = Solution().subsetsWithDup(arr);

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