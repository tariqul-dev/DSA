#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int index = 0;

    for (int num : nums)
    {
        if (index < 2 || num != nums[index - 2])
        {
            nums[index++] = num;
        }
    }

    return index;
}

int main()
{
    // vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    cout << removeDuplicates(nums) << endl;

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}