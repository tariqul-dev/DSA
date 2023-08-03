#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, map<int, bool> &helper)
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

            solve(nums, result, temp, helper);

            temp.pop_back();
            helper[i] = false;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> temp;
    map<int, bool> helper;

    solve(nums, result, temp, helper);

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