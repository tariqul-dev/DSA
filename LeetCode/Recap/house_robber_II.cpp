#include <bits/stdc++.h>

using namespace std;

int getRobValue(vector<int> &nums)
{

    int n = nums.size();
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

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);

        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    return max(getRobValue(temp1), getRobValue(temp2));
}

int main()
{
    vector<int> nums = {2, 3, 2};

    cout << rob(nums) << endl;

    return 0;
}