#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    // Kadane's Algorithm
    int sum = 0, maxValue = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > maxValue){
            maxValue = sum;
        }


        if (sum < 0){
            sum = 0;
        }
    }


    return maxValue;
    
}

int main()
{

    vector<int> nums = {5, 4, -1, 7, 8};

    cout << maxSubArray(nums) << endl;

    return 0;
}