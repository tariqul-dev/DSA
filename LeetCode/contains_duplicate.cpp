#include <bits/stdc++.h>

using namespace std;

void mergeAll(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int righ = mid + 1;

    while (left <= mid && righ <= high)
    {
        if (nums[left] < nums[righ])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[righ]);
            righ++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (righ <= high)
    {
        temp.push_back(nums[righ]);
        righ++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high)
{

    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    mergeAll(nums, low, mid, high);
}

bool containsDuplicate(vector<int> &nums)
{
    int size = nums.size();
    mergeSort(nums, 0, size - 1);

    for (int i = 1; i < size; i++)
    {
        int checkingXor = nums[i] ^ nums[i - 1];

        if (checkingXor == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<int> nums = {1, 2, 3, 1};
    // vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    // vector<int> nums = {7, 5, 78, 3, 1};

    cout << containsDuplicate(nums) << endl;

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}