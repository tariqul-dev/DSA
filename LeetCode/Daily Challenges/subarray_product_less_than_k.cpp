#include <bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int n = nums.size();

    int i = 0;
    int j = 0;

    int count = 0;
    int product = 1;

    if (k <= 1)
        return 0;

    while (j < n)
    {
        product *= nums[j];

        while (product >= k)
        {
            product /= nums[i];
            i++;
        }

        count += (j - i + 1);

        j++;
    }

    return count;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    cout << numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}