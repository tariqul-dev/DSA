#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
        result ^= nums[i];

    return result;
}

int main()
{
    vector<int> nums = {2, 2, 1};

    cout << singleNumber(nums) << endl;

    return 0;
}