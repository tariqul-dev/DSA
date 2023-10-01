#include <bits/stdc++.h>

using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    // vector<int> result;

    // int index = 0;

    // for (int i = 0; i < 2 * nums.size(); i++)
    // {
    //     if (i == nums.size())
    //         index = 0;
    //     result.push_back(nums[index++]);
    // }

    // return result;
    int n = nums.size();

    for (int i = 0; i < n; i++)
        nums.push_back(nums[i]);

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 1};
    vector<int> result = getConcatenation(nums);

    for (auto r : result)
    {
        cout << r << " ";
    }

    cout << endl;

    return 0;
}