#include <bits/stdc++.h>

using namespace std;

int f(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int left = f(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;

    if (index > 1)
        right = f(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(left, right);
}

int countUsingTabulation(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int x = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int y = INT_MAX;
        if (i > 1)
            y = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(x, y);
    }

    return dp[n - 1];
}

int spaceOptimized(int n, vector<int> &heights)
{
    int a = 0, b = 0; // b -> n - 1 and a -> n - 2

    for (int i = 1; i < n; i++)
    {
        int x = b + abs(heights[i] - heights[i - 1]);
        int y = INT_MAX;
        if (i > 1)
            y = a + abs(heights[i] - heights[i - 2]);

        a = b;
        b = min(x, y);
    }

    return b;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return spaceOptimized(n, heights);
}

int main()
{

    int n = 8;
    vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
    // vector<int> heights = {10, 20, 30, 10};

    cout << frogJump(n, heights) << endl;

    return 0;
}