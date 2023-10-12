#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    // Brute force
    // int n = nums.size();
    // vector<int> pref(n, 0);
    // vector<int> post(n, 0);

    // vector<int> ans(n, 0);

    // pref[0] = nums[0];
    // post[n - 1] = nums[n - 1];

    // for (int i = 1; i < n; i++)
    //     pref[i] = pref[i - 1] * nums[i];

    // for (int i = n - 2; i >= 0; i--)
    //     post[i] = post[i + 1] * nums[i];

    // ans[0] = post[1];

    // for (int i = 1; i < n - 1; i++)
    //     ans[i] = pref[i - 1] * post[i + 1];

    // ans[n - 1] = pref[n - 2];

    // return ans;

    // optimize
    int n = nums.size();
    vector<int> ans(n, 0);

    ans[0] = 1;

    for (int i = 1; i < n; i++)
        ans[i] = ans[i - 1] * nums[i - 1];

    int right = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= right;
        right *= nums[i];
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);

    print(ans);

    return 0;
}