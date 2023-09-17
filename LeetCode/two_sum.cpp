#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int remain = target - nums[i];
        if (map.find(remain) != map.end())
        {
            cout << map[remain] << endl;
            return {map[remain], i};
        }

        map[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}