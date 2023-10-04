#include <bits/stdc++.h>

using namespace std;

int getDigitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int differenceOfSum(vector<int> &nums)
{
    int eleSum = 0, digitSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        eleSum += nums[i];
        if (nums[i] > 0)
            digitSum += getDigitSum(nums[i]);
    }


    return abs(eleSum - digitSum);
}

int main()
{

    vector<int> nums = {1, 15, 6, 3};

    cout << differenceOfSum(nums) << endl;

    return 0;
}