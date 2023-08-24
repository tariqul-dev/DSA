#include <bits/stdc++.h>

using namespace std;

void findSubSets(vector<int> &nums, vector<vector<int>> &result, vector<int> temp, int index = 0)
{
    if (index == nums.size())
    {
        result.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);

    findSubSets(nums, result, temp, index + 1);

    temp.pop_back();

    findSubSets(nums, result, temp, index + 1);
}

vector<vector<int>> subset(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> temp;

    findSubSets(nums, result, temp);

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result = subset(arr);

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