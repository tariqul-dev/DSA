#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    // unordered_map<int, int> mp;
    // mp.insert({0, 1});

    // int count = 0;
    // int prefSum = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     prefSum += nums[i];
    //     int remain = prefSum - goal;

    //     if (mp.find(remain) != mp.end())
    //     {
    //         count += mp[remain];
    //     }

    //     mp[prefSum]++;
    // }

    // return count;

    // Sliding window solution

    int n = nums.size();

    int i = 0;
    int j = 0;

    int count = 0;
    int countZero = 0;
    int windowSum = 0;

    while (j < n)
    {
        windowSum += nums[j];

        while (i < j && (nums[i] == 0 || windowSum > goal))
        {

            if (nums[i] == 0)
            {
                countZero++;
            }
            else
            {
                countZero = 0;
            }

            windowSum -= nums[i];
            i++;
        }

        if (windowSum == goal)
        {
            count += 1 + countZero;
        }

        j++;
    }

    return count;
}

int main()
{

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << numSubarraysWithSum(nums, goal) << endl;

    return 0;
}