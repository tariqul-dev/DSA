#include <bits/stdc++.h>

using namespace std;

void print(vector<int> nums)
{
    for (int n : nums)
        cout << n << " ";
    cout << endl;
}

void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++, mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    print(nums);

    sortColors(nums);

    print(nums);

    return 0;
}