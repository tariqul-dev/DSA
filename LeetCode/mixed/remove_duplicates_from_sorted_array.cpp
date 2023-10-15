#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[count] = nums[i];
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // vector<int> nums = {1, 1, 2};
    cout << removeDuplicates(nums) << endl;

    return 0;
}