#include <bits/stdc++.h>

using namespace std;

// brute
// int removeElement(vector<int> &nums, int val)
// {
//     int inf = INT_MIN;
//     int len = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int xOr = val ^ nums[i];

//         if (xOr == 0)
//         {
//             nums[i] = inf;
//         }
//         else
//             len++;
//     }

//     int indexOfZero = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == inf)
//         {
//             indexOfZero = i;
//             break;
//         }
//     }

//     for (int i = indexOfZero + 1; i < nums.size(); i++)
//     {
//         if (nums[i] != inf)
//         {
//             swap(nums[indexOfZero], nums[i]);
//             indexOfZero++;
//         }
//     }

//     return len;
// }

int removeElement(vector<int> &nums, int val)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    cout << removeElement(nums, val) << endl;

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}