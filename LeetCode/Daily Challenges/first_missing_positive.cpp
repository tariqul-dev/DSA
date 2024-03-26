#include <bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();

    bool isOnePresent = false;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            isOnePresent = true;

        if (nums[i] <= 0 || nums[i] > n)
        {
            nums[i] = 1;
        }
    }

    if (isOnePresent == false)
        return 1;

    for (int i = 0; i < n; i++)
    {
        int num = abs(nums[i]);
        int index = num - 1;

        if (nums[index] < 0)
            continue;

        nums[index] *= -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            return i + 1;
    }

    return n + 1;
}

int main()
{

    vector<int> nums = {3, 4, -1, 1};

    cout << firstMissingPositive(nums) << endl;

    return 0;
}