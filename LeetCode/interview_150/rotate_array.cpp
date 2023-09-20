#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int> &nums, int low, int high)
{
    while (low <= high)
    {
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
        low++, high--;
    }
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n <= 1)
        return;

    cout << "N: " << n << " K: " << k << endl;

    // if (k > n)
    //     k = n - k % n - 1;
    // else
        k = n - k % n - 1;

    cout << "N: " << n << " K: " << k << endl;

    reverse(nums, 0, k);
    reverse(nums, k + 1, n - 1);
    reverse(nums, 0, n - 1);
}

int main()
{
    int k = 3;
    // vector<int> nums = {-1, -100, 3, 99};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums = {1, 2};

    rotate(nums, k);

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}