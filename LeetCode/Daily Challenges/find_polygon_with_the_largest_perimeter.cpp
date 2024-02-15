#include <bits/stdc++.h>

using namespace std;

long long largestPerimeter(vector<int> &nums)
{
    int n = nums.size();
    long long prefSum = 0;
    long long result = -1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (prefSum > nums[i])
        {
            result = prefSum + nums[i];
        }

        prefSum += nums[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 12, 1, 2, 5, 50, 3};

    cout << largestPerimeter(nums) << endl;

    return 0;
}