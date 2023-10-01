#include <bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    int i = 0;
    int size = nums.size();
    vector<int> result;

    while (n < size)
    {
        result.push_back(nums[i++]);
        result.push_back(nums[n++]);
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 4, 3, 2, 1};
    int n = 4;

    for (auto x : shuffle(nums, n))
        cout << x << " ";
    cout << endl;

    return 0;
}