#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (auto n : nums)
    {
        ans ^= n;
    }
    return ans;
}

int main()
{

    // vector<int> nums = {-336, 513, -560, -481, -174, 101, -997, 40, -527, -784, -283, -336, 513, -560, -481, -174, 101, -997, 40, -527, -784, -283, 354};

    vector<int> nums = {40, 40, 101, 101, 354, 513, 513};

    cout << singleNumber(nums) << endl;

    return 0;
}