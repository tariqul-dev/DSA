#include <bits/stdc++.h>

using namespace std;

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    int n = nums.size();
    int minEleIndex = -1;
    int maxEleIndex = -1;
    int culpritIndex = -1;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
        {
            culpritIndex = i;
        }

        if (nums[i] == minK)
            minEleIndex = i;

        if (nums[i] == maxK)
            maxEleIndex = i;

        long long smaller = min(minEleIndex, maxEleIndex);
        long long temp = smaller - culpritIndex;

        ans += (temp <= 0) ? 0 : temp;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1, maxK = 5;

    cout << countSubarrays(nums, minK, maxK) << endl;

    return 0;
}