#include <bits/stdc++.h>

using namespace std;

int countPairs(vector<int> &nums, int k)
{
    // int count = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //         if (nums[i] == nums[j] && (i * j) % k == 0)
    //             count++;
    // }

    // return count;

    // hashing
    unordered_map<int, vector<int>> freqMap;

    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (freqMap.find(nums[i]) != freqMap.end())
        {
            for (auto j : freqMap[nums[i]])
            {
                if ((i * j) % k == 0)
                    count++;
            }
        }

        freqMap[nums[i]].push_back(i);
    }

    return count;
}

int main()
{

    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    cout << countPairs(nums, k) << endl;

    return 0;
}