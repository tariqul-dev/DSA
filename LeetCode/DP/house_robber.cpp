#include <bits/stdc++.h>

using namespace std;

int recursiveWay(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[0];
    if (index < 0)
        return 0;

    int robbingPrice = nums[index];
    if (index > 1)
        robbingPrice += recursiveWay(index - 2, nums);
    int notRobbingPrice = recursiveWay(index - 1, nums);

    return max(robbingPrice, notRobbingPrice);
}

int memoizationTechniq(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
        return nums[index];

    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = nums[index];
    if (index > 1)
        pick += memoizationTechniq(index - 2, nums, dp);

    int notPick = memoizationTechniq(index - 1, nums, dp);

    return dp[index] = max(pick, notPick);
}

int tabulationTechniq(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);

    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[nums.size() - 1];
}

int spaceOptimize(vector<int> &nums)
{
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int notPick = prev;

        int current = max(pick, notPick);
        prev2 = prev;
        prev = current;
    }

    return prev;
}

int rob(vector<int> &nums)
{
    // vector<int> dp(nums.size(), -1);
    // return memoizationTechniq(nums.size() - 1, nums, dp);

    // return tabulationTechniq(nums);
    return spaceOptimize(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    // vector<int> nums = {2, 7, 9, 3, 1};

    cout << rob(nums) << endl;

    return 0;
}