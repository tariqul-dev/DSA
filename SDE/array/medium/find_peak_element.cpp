#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    // Liner search
    // int maxValue = nums[0];
    // int maxIndex = 0;

    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[i] > maxValue)
    //     {
    //         maxValue = nums[i];
    //         maxIndex = i;
    //     }
    // }

    // return maxIndex;

    // Binary search
    int n = nums.size();
    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        else if (nums[mid] > nums[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{

    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    cout << findPeakElement(nums) << endl;

    return 0;
}