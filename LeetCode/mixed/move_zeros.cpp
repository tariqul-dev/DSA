#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // cout << i << " " << endl;
        if (nums[i] != 0)
        {
            cout << nums[j] << " " << nums[i] << endl;
            swap(nums[j], nums[i]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums = {1};

    moveZeroes(nums);

    for (auto i : nums)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}