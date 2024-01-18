#include <bits/stdc++.h>

using namespace std;

void print(vector<int> nums)
{
    for (int n : nums)
    {
        cout << n << " ";
    }

    cout << endl;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        int remain = target - nums[i];

        if (mpp.find(remain) != mpp.end())
        {
            return {mpp[remain], i};
        }

        mpp[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    print(twoSum(nums, target));

    return 0;
}