#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int index = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index++] = nums[i];
        }
    }

    return index;
}

int main()
{

    vector<int> nums = {1, 1, 2};

    cout << removeDuplicates(nums) << endl;

    for (int i : nums)
        cout << i << " ";
    cout << endl;
}