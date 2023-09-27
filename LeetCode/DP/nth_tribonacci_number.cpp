#include <bits/stdc++.h>

using namespace std;

int tribonacciRecursion(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;

    return tribonacciRecursion(n - 1) + tribonacciRecursion(n - 2) + tribonacciRecursion(n - 3);
}

int tribonacciRecursionMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = tribonacciRecursionMemo(n - 1, dp) + tribonacciRecursionMemo(n - 2, dp) + tribonacciRecursionMemo(n - 3, dp);
}

int tribonacciTabulation(int n)
{
    vector<int> dp(n + 3, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << dp[i] << " ";
    }

    cout << endl;

    return dp[n];
}

int tribonacciSpaceOptimized(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;

    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;

    for (int i = 3; i <= n; i++)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }

    return d;
}

int tribonacci(int n)
{
    // vector<int> dp(n + 1, -1);
    return tribonacciSpaceOptimized(n);
}

int main()
{
    int n = 2;

    cout << tribonacci(n) << endl;

    return 0;
}