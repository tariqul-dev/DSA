#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {

        if (nums[mid] == target)
            return true;

        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++, high--;
            continue;
        }

        if (nums[low] <= nums[mid]) // sorted
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else // not sorted
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        mid = (low + high) / 2;
    }
    return false;
}

int main()
{
    vector<int> nums = {5, 1, 3};
    int target = 3;

    cout << search(nums, target) << endl;

    return 0;
}