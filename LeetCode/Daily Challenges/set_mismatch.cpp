#include <bits/stdc++.h>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    int n = nums.size();
    int duplicateVal = -1;
    int missingVal = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            duplicateVal = abs(nums[i]);
        }
        else
        {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            missingVal = i + 1;
            break;
        }
    }

    return {duplicateVal, missingVal};
}

int main()
{
    vector<int> nums = {2, 2};

    vector<int> res = findErrorNums(nums);

    for (int &i : res)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}