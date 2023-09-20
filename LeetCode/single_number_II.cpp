#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = 0;

    for (auto n : nums)
    {
        result ^= n;
    }

    return result;
}

int main()
{

    vector<int> nums = {2, 2, 3, 2};

    cout << singleNumber(nums) << endl;

    return 0;
}