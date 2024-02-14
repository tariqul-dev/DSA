#include <bits/stdc++.h>

using namespace std;

// vector<int> rearrangeArray(vector<int> &nums)
// {
//     vector<int> positive;
//     vector<int> negative;
//     vector<int> result;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] < 0)
//             negative.push_back(nums[i]);
//         else
//             positive.push_back(nums[i]);
//     }

//     int i = 0, j = 0;
//     while (i < positive.size() || j < negative.size())
//     {
//         result.push_back(positive[i]);
//         result.push_back(negative[j]);

//         i++, j++;
//     }

//     return result;
// }

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    int positiveIndex = 0;
    int negativeIndex = 1;

    vector<int> result(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            result[negativeIndex] = nums[i];
            negativeIndex += 2;
        }
        else
        {
            result[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
    }

    return result;
}

int main()
{

    vector<int> nums = {3, 1, -2, -5, 2, -4};

    for (const int &num : rearrangeArray(nums))
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}