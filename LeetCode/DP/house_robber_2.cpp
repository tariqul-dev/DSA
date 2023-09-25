#include <bits/stdc++.h>

using namespace std;

int robSpaceOptimized(int start, int end, vector<int> &nums)
{
    int prev = nums[start];
    int prev2 = 0;

    for (int i = start + 1; i < end; i++)
    {
        int pick = nums[i];
        if (i > start + 1)
            pick += prev2;
        int notPick = prev;

        prev2 = prev;
        prev = max(pick, notPick);
    }

    return prev;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int ans1 = robSpaceOptimized(0, nums.size() - 1, nums);
    int ans2 = robSpaceOptimized(1, nums.size(), nums);

    return max(ans1, ans2);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    // vector<int> nums = {1, 2, 3};
    // vector<int> nums = {2, 7, 9, 3, 1};

    cout << rob(nums) << endl;

    return 0;
}