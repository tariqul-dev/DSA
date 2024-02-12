#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int element = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (count == 0)
        {
            count = 1;
            element = nums[i];
        }
        else if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return element;
}

int main()
{

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << majorityElement(nums) << endl;

    return 0;
}