#include <bits/stdc++.h>

using namespace std;

// min heap -> tc: O(n + klogn), sc: O(n)
// int findKthLargest(vector<int> &nums, int k)
// {
//     // priority_queue<int, vector<int>, greater<int>> pq;
//     priority_queue<int> pq;

//     for (auto num : nums)
//     {
//         pq.push(-num);

//         if (pq.size() > k)
//             pq.pop();
//     }

//     return -pq.top();
// }

// Quick select -> tc: average O(n), worst O(n^2), sc: O(n)

int quickSelect(vector<int> &nums, int &k, int left, int right)
{
    int pivot = nums[right], currIndex = left;

    for (int index = left; index < right; index++)
    {
        if (nums[index] < pivot)
        {
            swap(nums[currIndex], nums[index]);
            currIndex++;
        }
    }

    swap(nums[currIndex], nums[right]);

    return currIndex;
}

int findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1, kthElement;

    while (true)
    {
        int currIndex = quickSelect(nums, k, left, right);
        cout << "CurrIndex: " << currIndex << endl;

        if (currIndex == k)
        {
            kthElement = nums[currIndex];
            break;
        }
        if (currIndex < k)
            left = currIndex + 1;

        else
            right = currIndex - 1;
    }

    return kthElement;
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    int k = 4;

    cout << findKthLargest(nums, k) << endl;

    return 0;
}