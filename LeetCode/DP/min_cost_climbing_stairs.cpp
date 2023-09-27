#include <bits/stdc++.h>

using namespace std;

int minCostRecursive(int index, vector<int> &cost, vector<int> &dp)
{
    if (index < 0)
        return 0;

    if (index <= 1)
        return cost[index];

    if (dp[index] != -1)
        return dp[index];

    int left = minCostRecursive(index - 1, cost, dp);

    int right = minCostRecursive(index - 2, cost, dp);

    return dp[index] = cost[index] + min(left, right);
}

int minCostTabulation(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, 0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

int minCostSpaceOptimized(vector<int> &cost)
{
    int n = cost.size();
    int prev2 = cost[0], prev = cost[1];

    if (n < 2)
        return min(prev2, prev);

    for (int i = 2; i < n; i++)
    {
        int current = cost[i] + min(prev, prev2);
        prev2 = prev;
        prev = current;
    }

    return min(prev2, prev);
}

int minCostClimbingStairs(vector<int> &cost)
{
    // int n = cost.size();
    // vector<int> dp(n + 1, -1);
    // return min(minCostRecursive(n - 1, cost, dp), minCostRecursive(n - 2, cost, dp));
    return minCostSpaceOptimized(cost);
}

int main()
{

    // vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> cost = {10, 15, 20};

    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}