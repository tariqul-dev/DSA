#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    vector<int> n;
    int size = nums.size();

    for (int i = 0; i < size - 1; i++)
    {
        int xOR = nums[i] ^ nums[i + 1];

        if (xOR != 0)
        {
            n.push_back(nums[i]);
        }
    }

    int xOr = nums[size - 1] ^ n[n.size() - 1];

    if (xOr != 0)
    {
        n.push_back(nums[size - 1]);
    }

    nums = n;

    return nums.size();
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // vector<int> nums = {1, 1, 2};
    cout << removeDuplicates(nums) << endl;

    return 0;
}