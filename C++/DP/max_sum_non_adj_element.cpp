#include <bits/stdc++.h>

using namespace std;

// Maximum sum of non adjacent element
// 2 1 1 2 -> 4

int recursion(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;

    int pick = nums[index] + recursion(index - 2, nums);
    int notPick = recursion(index - 1, nums);

    return max(pick, notPick);
}

int memoizationOptimize(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int pick = nums[index] + memoizationOptimize(index - 2, nums, dp);
    int notPick = memoizationOptimize(index - 1, nums, dp);

    return dp[index] = max(pick, notPick);
}

int tabulation(vector<int> &nums)
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

int spaceOptimized(vector<int> &nums)
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

int maximumNonAdjacentSum(vector<int> &nums)
{
    // int n = nums.size() - 1;
    // vector<int> dp(n + 1, -1);
    // return memoizationOptimize(n, nums, dp);
    return spaceOptimized(nums);
}

int main()
{
    vector<int> nums = {2, 1, 1, 2};
    // vector<int> nums = {2, 7, 9, 3, 1};

    cout << maximumNonAdjacentSum(nums) << endl;

    return 0;
}