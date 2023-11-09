#include <bits/stdc++.h>

using namespace std;

void print(vector<int> nums)
{
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int index = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i >= index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[index], nums[i]);
            break;
        }
    }

    reverse(nums.begin() + index + 1, nums.end());
}

int main()
{
    vector<int> nums = {1,2,3};

    nextPermutation(nums);

    print(nums);

    return 0;
}