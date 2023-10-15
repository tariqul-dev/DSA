#include <bits/stdc++.h>

using namespace std;

// magic
// int singleNumber(vector<int> &nums)
// {
//     int ones = 0;
//     int twos = 0;

//     for (int num : nums)
//     {
//         ones = (ones ^ num) & (~twos);
//         twos = (twos ^ num) & (~ones);
//     }

//     return ones;
// }

// Bit manipulation
int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int num : nums)
        {
            count += (num >> i) & 1;
        }

        count %= 3;
        result = result | (count << i);
    }

    return result;
}

int main()
{

    // vector<int> nums = {2, 2, 3, 2};
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    cout << singleNumber(nums) << endl;

    return 0;
}