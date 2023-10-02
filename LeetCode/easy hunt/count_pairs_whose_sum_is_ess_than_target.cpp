#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (nums[left] < nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }

    while (left <= mid)
        temp.push_back(nums[left++]);

    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
}

void mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    merge(nums, low, mid, high);
}

int countPairs(vector<int> &nums, int target)
{
    // int count = 0;
    // for (int i = 0; i < nums.size(); i++)

    //     for (int j = i + 1; j < nums.size(); j++)
    //         if (nums[i] + nums[j] < target)
    //             count++;

    // return count;

    int count = 0;

    mergeSort(nums, 0, nums.size() - 1);

    for (int num : nums)
        cout << num << " ";
    cout << endl;

    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] + nums[right] < target)
        {
            count += right - left;
            left++;
        }
        else
            right--;
    }
    return count;
}

int main()
{
    vector<int> nums = {-6, 2, 5, -2, -7, -1, 3};
    int target = -2;

    cout << countPairs(nums, target);

    return 0;
}