#include <bits/stdc++.h>

using namespace std;

void print(vector<int> nums)
{
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans = nums;
    int posIndex = 0, negIndex = 1;

    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] < 0)
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {3, 1, -2, -5, 2, -4};

    print(rearrangeArray(nums));

    return 0;
}