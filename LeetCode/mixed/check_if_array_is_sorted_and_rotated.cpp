#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[(i + 1) % nums.size()])
            count++;

        if (count > 1)
            return false;
    }

    return true;
}

int main()
{

    vector<int> nums = {3};


    cout << check(nums) << endl;

    return 0;
}
