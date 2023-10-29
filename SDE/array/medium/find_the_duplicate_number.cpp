#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    vector<int> temp = nums;

    sort(temp.begin(), temp.end());

    int j = 1;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == temp[j])
        {
            return temp[i];
        }
        j++;
    }

    return - 1;
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};

    cout << findDuplicate(nums) << endl;

    return 0;
}