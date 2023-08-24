#include <bits/stdc++.h>

using namespace std;

void print(vector<int> nums, int size, int index = 0)
{
    if (index == size)
        return;
    cout << nums[index] << " ";

    print(nums, size, index + 1);
}

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

vector<vector<int>> permute(vector<int> nums)
{
    vector<vector<int>> result;
    vector<int> temp;
    map<int, bool> helper;

    solve(nums, result, temp, helper);

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = permute(nums);

    for (int i = 0; i < result.size(); i++)
    {
        print(result[i], result[i].size());

        cout << endl;
    }

    /*
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1

    */

    return 0;
}