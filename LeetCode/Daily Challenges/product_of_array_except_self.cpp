#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;

    for (int i = 1; i < n; i++)
    {
        ans[i] = nums[i - 1] * ans[i - 1];
    }

    int sufixProduct = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * sufixProduct;
        sufixProduct *= nums[i];
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4};

    for (int &n : productExceptSelf(nums))
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}