#include <bits/stdc++.h>

using namespace std;

// with extra space

void calculatePermute(vector<int> &nums, vector<int> &ds, map<int, int> &isTaken, vector<vector<int>> &result)
{
    if (ds.size() == nums.size())
    {
        result.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (isTaken[nums[i]] != 1)
        {
            ds.push_back(nums[i]);
            isTaken[nums[i]] = 1;

            calculatePermute(nums, ds, isTaken, result);

            ds.pop_back();
            isTaken[nums[i]] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    map<int, int> isTaken;
    vector<int> ds;
    calculatePermute(nums, ds, isTaken, result);

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = permute(nums);

    for (auto r : result)
    {
        for (auto d : r)
            cout << d << " ";
        cout << endl;
    }

    return 0;
}