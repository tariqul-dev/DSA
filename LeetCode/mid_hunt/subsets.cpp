#include <bits/stdc++.h>

using namespace std;

void findingSubsets(vector<int> &nums, int index, vector<int> &ds, vector<vector<int>> &result)
{
    if (index >= nums.size())
    {
        result.push_back(ds);
        return;
    }

    ds.push_back(nums[index]);
    findingSubsets(nums, index + 1, ds, result);

    ds.pop_back();
    findingSubsets(nums, index + 1, ds, result);
}

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> result;
    vector<int> ds;

    findingSubsets(nums, 0, ds, result);

    return result;
}

int main()
{

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (auto r : result)
    {
        for (auto d : r)
            cout << d << " ";
        cout << endl;
    }

    return 0;
}