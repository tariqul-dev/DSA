#include <bits/stdc++.h>

using namespace std;

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;
    mp.insert({0, -1});

    int result = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += (nums[i] == 1) ? 1 : -1;

        if (mp.find(prefixSum) != mp.end())
        {
            result = max(result, i - mp[prefixSum]);
        }
        else
        {
            mp[prefixSum] = i;
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {0, 1, 0};

    cout << findMaxLength(nums) << endl;

    return 0;
}