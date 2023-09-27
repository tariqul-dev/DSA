#include <bits/stdc++.h>

using namespace std;

int fibRecursion(int n)
{
    if (n <= 1)
        return n;

    return fibRecursion(n - 1) + fibRecursion(n - 2);
}

int fibRecursionMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibRecursion(n - 1) + fibRecursion(n - 2);
}

int fibTabulation(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibSpaceOptimize(int n)
{
    if (n == 0)
        return 0;

    int a = 0;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int fib(int n)
{
    // vector<int> dp(n + 1, -1);
    // return fibRecursionMemo(n, dp);
    return fibSpaceOptimize(n);
}

int main()
{
    int n = 6;

    cout << fib(n) << endl;

    return 0;
}