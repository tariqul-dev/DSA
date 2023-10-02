#include <bits/stdc++.h>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    // brute force
    // vector<int> result;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < nums.size(); j++)
    //     {
    //         if (i != j && nums[i] > nums[j])
    //             count++;
    //     }

    //     result.push_back(count);
    // }

    // return result;

    // using prefix sum
    int count[101] = {0};
    vector<int> result;

    // frequency counting
    for (int num : nums)
        count[num]++;

    // prefix sum calcuating
    for (int i = 1; i <= 100; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == 0)
            result.push_back(0);
        else
            result.push_back(count[nums[i] - 1]);

    return result;
}

int main()
{

    vector<int> nums = {6, 5, 4, 8};

    for (int num : smallerNumbersThanCurrent(nums))
        cout << num << " ";
    cout << endl;
}