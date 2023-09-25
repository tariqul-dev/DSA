#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &nums)
{
    int sumOdd = 0, sumEven = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i & 1)
        {
            sumOdd += nums[i];
        }
        else
        {
            sumEven += nums[i];
        }
    }

    return max(sumEven, sumOdd);
}

int main()
{
    vector<int> nums = {1,2,3,1};
    // vector<int> nums = {2, 7, 9, 3, 1};

    cout << rob(nums) << endl;

    return 0;
}