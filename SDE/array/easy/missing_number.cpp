#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int result = nums.size();

    for (int i = 0; i < nums.size(); i++)
        result ^= i ^ nums[i];

    return result;
}

int main()
{

    vector<int> nums = {3, 0, 1};

    cout << missingNumber(nums) << endl;

    return 0;
}