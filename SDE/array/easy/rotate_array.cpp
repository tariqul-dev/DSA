#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (int a : ans)
        cout << a << " ";
    cout << endl;
}

void reverse(int left, int right, vector<int> &nums)
{
    while (left < right)
        swap(nums[left++], nums[right--]);
}

void rotate(vector<int> &nums, int k)
{

    k = nums.size() - k % nums.size() - 1;

    reverse(0, k, nums);
    reverse(k + 1, nums.size() - 1, nums);
    reverse(0, nums.size() - 1, nums);
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    print(nums);

    return 0;
}