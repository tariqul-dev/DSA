#include <bits/stdc++.h>

using namespace std;

int countSetBit(int n)
{
    int count = 0;

    while (n > 0)
    {
        count += n & 1;

        n >>= 1;
    }

    return count;
}

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
        if (countSetBit(i) == k)
            sum += nums[i];

    return sum;
}

int main()
{

    vector<int> nums = {5, 10, 1, 5, 2};
    int k = 1;

    cout << sumIndicesWithKSetBits(nums, k);

    return 0;
}