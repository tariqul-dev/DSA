#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> sumMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int remain = target - nums[i];

        if (sumMap.find(remain) != sumMap.end())
            return {sumMap[remain], i};

        sumMap[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    print(twoSum(nums, target));

    return 0;
}