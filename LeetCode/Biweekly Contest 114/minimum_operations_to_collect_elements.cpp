#include <bits/stdc++.h>

using namespace std;

int minOperations(vector<int> &nums, int k)
{
    set<int> s;
    int len = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] >= 1 && nums[i] <= k)
            s.insert(nums[i]);

        len++;

        if (s.size() == k)
            return len;
    }

    return len;
}

int main()
{
    vector<int> nums = {3, 2, 5, 3, 1};
    int k = 3;

    cout << minOperations(nums, k);

    return 0;
}