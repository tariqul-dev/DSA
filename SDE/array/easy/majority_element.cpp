#include <bits/stdc++.h>

using namespace std;

// better solution
// int majorityElement(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int maxCount = 1;
//     int maxElement = nums[0];
//     int count = 1;

//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i - 1] == nums[i])
//         {
//             count++;
//         }
//         else
//         {
//             count = 1;
//         }

//         if (count > maxCount)
//         {
//             maxCount = count;
//             maxElement = nums[i];
//         }
//     }

//     return maxElement;
// }

// Moore's votting algorithm (optimal)
int majorityElement(vector<int> &nums)
{
    int element = 0;
    int count = 0;

    // Moore's votting algorith
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            element = nums[i];
        }
        else if (nums[i] == element)
            count++;
        else
            count--;
    }

    return element;

    // varifing the element
    // count = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] == element)
    //         count++;
    // }

    // if (count > nums.size() / 2)
    //     return element;

    // return -1;
}

int main()
{

    vector<int> nums = {2, 2, 4, 1, 1, 2, 4, 4,4};

    cout << majorityElement(nums) << endl;

    return 0;
}