#include <bits/stdc++.h>

using namespace std;

// void solve(int idx, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev)
// {
//     if (idx >= nums.size())
//     {
//         if (temp.size() > result.size())
//             result = temp;

//         return;
//     }

//     // Taking condition
//     if (prev == -1 || nums[idx] % prev == 0){
//         temp.push_back(nums[idx]);
//         solve(idx + 1, nums, result, temp, nums[idx]);

//         // Not taking part or backtracking
//         temp.pop_back();
//     }

//     solve(idx + 1, nums, result, temp, prev);
// }

// vector<int> largestDivisibleSubset(vector<int> &nums)
// {
//     vector<int> result;
//     vector<int> temp;

//     sort(nums.begin(), nums.end());

//     solve(0, nums, result, temp, -1);

//     return result;
// }

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> prevIndex(n, -1);

    int lastSelectedIndex = 0;
    int maxElement = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0)
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;
                }

                if (dp[i] > maxElement)
                {
                    maxElement = dp[i];
                    lastSelectedIndex = i;
                }
            }
        }
    }

    vector<int> result;

    while (lastSelectedIndex != -1)
    {
        result.push_back(nums[lastSelectedIndex]);
        lastSelectedIndex = prevIndex[lastSelectedIndex];
    }

    return result;
}

int main()
{

    vector<int> nums = {15, 3, 4, 64, 32};

    for (int &n : largestDivisibleSubset(nums))
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}