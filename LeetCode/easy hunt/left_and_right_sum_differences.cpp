#include <bits/stdc++.h>

using namespace std;

vector<int> leftRightDifference(vector<int> &nums)
{
    // vector<int> left(nums.size(), 0), right(nums.size(), 0), ans(nums.size(), 0);

    // left[0] = 0;
    // for (int i = 1; i < nums.size(); i++)
    //     left[i] = left[i - 1] + nums[i - 1];

    // right[nums.size() - 1] = 0;

    // for (int i = nums.size() - 2; i >= 0; i--)
    //     right[i] = right[i + 1] + nums[i + 1];

    // for (int i = 0; i < nums.size(); i++)
    //     ans[i] = abs(left[i] - right[i]);

    // return ans;

    vector<int> ans;
    int leftSum = 0, rightSum = 0;

    for (int i = 0; i < nums.size(); i++)
        rightSum += nums[i];

    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        ans.push_back(abs(leftSum - rightSum));

        leftSum += nums[i];
    }

    return ans;
}

int main()
{

    vector<int> nums = {10, 4, 8, 3};

    for (int n : leftRightDifference(nums))
        cout << n << " ";
    cout << endl;
}