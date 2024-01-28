#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    mp.insert({0, 1});

    int result = 0;

    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int remain = sum - k;

        if (mp.find(remain) != mp.end())
        {
            result += mp[remain];
        }

        mp[sum]++;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << subarraySum(nums, k) << endl;

    return 0;
}