#include <bits/stdc++.h>

using namespace std;

int maxSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    int length = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        mp[nums[j]]++;

        while (i < j && mp[nums[j]] > k)
        {
            mp[nums[i]]--;
            i++;
        }

        length = max(length, j - i + 1);
        j++;
    }

    return length;
}

int main()
{

    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    cout << maxSubarrayLength(nums, k) << endl;

    return 0;
}