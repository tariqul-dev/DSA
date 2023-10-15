#include <bits/stdc++.h>

using namespace std;

bool isMonotonic(vector<int> &nums)
{
    // int j = 0;

    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[j] <= nums[i])
    //         j++;
    // }

    // if (j == nums.size() - 1) return true;

    // j = 0;

    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[j] >= nums[i])
    //         j++;
        
    // }
    

    // return j == nums.size() - 1;

    bool inc = true, dec = true;

    for (int i = 1; i < nums.size(); i++)
    {
        inc &= nums[i - 1] <= nums[i];
        dec &= nums[i - 1] >= nums[i];
    }
    
    return inc || dec;
}

int main()
{
    vector<int> nums = {6, 5, 4, 4};

    cout << isMonotonic(nums) << endl;

    return 0;
}