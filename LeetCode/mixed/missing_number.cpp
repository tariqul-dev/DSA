#include <bits/stdc++.h>

using namespace std;

// brute
// int missingNumber(vector<int> &nums)
// {
//
//     if (nums[0] != 0)
//     {
//         return nums[0] - 1;
//     }
//
//     sort(nums.begin(), nums.end());
//
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i - 1] + 1 != nums[i])
//         {
//             return nums[i - 1] + 1;
//         }
//     }
//
//     return nums[nums.size() - 1] + 1;
// }

// xor
int missingNumber(vector<int> &nums)
{
    int result = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        result ^= i ^ nums[i];
    }

    return result;
}

int main()
{

    vector<int> nums = {1};
    // vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    cout << missingNumber(nums) << endl;

    return 0;
}