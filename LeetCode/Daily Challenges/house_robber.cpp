#include <bits/stdc++.h>

using namespace std;

//! Memoization

// int calculateVal(int index, vector<int> &nums, vector<int> &dp)
// {
//     if (index == 0)
//         return nums[index];
//     if (index < 0)
//         return 0;

//     if (dp[index] != -1)
//         return dp[index];

//     int pickedValue = nums[index] + calculateVal(index - 2, nums, dp);
//     int notPickedValue = 0 + calculateVal(index - 1, nums, dp);

//     return dp[index] = max(pickedValue, notPickedValue);
// }

// int rob(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);

//     return calculateVal(n - 1, nums, dp);
// }

//! Tabulation
// int rob(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);

//     dp[0] = nums[0];

//     for (int index = 1; index < n; index++)
//     {
//         int pickedValue = nums[index];
//         if (index > 1)
//             pickedValue += dp[index - 2];

//         int notPickedValue = 0 + dp[index - 1];

//         dp[index] = max(pickedValue, notPickedValue);
//     }
//     return dp[n - 1];
// }

// ! Space optimized
int rob(vector<int> &nums)
{
    int n = nums.size();
    /*
    prev1 is representing dp[i - 1]
    prev2 is representing dp[i - 2]
    */
    int prev1 = nums[0];
    int prev2 = 0;

    for (int index = 1; index < n; index++)
    {
        int pickedValue = nums[index];
        if (index > 1)
            pickedValue += prev2;

        int notPickedValue = 0 + prev1;

        prev2 = prev1;
        prev1 = max(pickedValue, notPickedValue);
    }
    return prev1;
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1, 4};

    cout << rob(nums) << endl;
    return 0;
}