#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[1001][1001];

int solve(int n, int k)
{
    if (n == 0)
        return 0;

    if (k == 0)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    int result = 0;

    for (int i = 0; i <= min(n - 1, k); i++)
    {
        result = (result + solve(n - 1, k - i)) % mod;
    }

    return dp[n][k] = result;
}

int kInversePairs(int n, int k)
{
    memset(dp, -1, sizeof(dp));

    return solve(n, k);
}

int main()
{

    int n = 3, k = 1;

    cout << kInversePairs(n, k) << endl;

    return 0;
}