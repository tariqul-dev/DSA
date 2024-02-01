#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i += 3)
    {
        if (nums[i + 2] - nums[i] > k)
            return {};

        result.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }

    return result;
}

int main()
{

    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;

    vector<vector<int>> result = divideArray(nums, k);

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