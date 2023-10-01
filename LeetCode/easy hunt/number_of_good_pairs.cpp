#include <bits/stdc++.h>

using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    // int count = 0;

    // for (int i = 0; i < nums.size(); i++)
    //     for (int j = 1; j < nums.size(); j++)
    //         if (i < j && nums[i] == nums[j])
    //             count++;

    // return count;
    unordered_map<int, int> numCounts;
    int count = 0;

    for (auto num : nums)
    {
        if (numCounts.find(num) != numCounts.end())
        {
            count += numCounts[num];
            numCounts[num]++;
        }
        else
        {
            numCounts[num] = 1;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {1,2,3,1,1,3};

    cout << numIdenticalPairs(nums);

    return 0;
}