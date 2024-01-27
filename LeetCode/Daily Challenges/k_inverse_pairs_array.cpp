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

int tablulation(int n, int k)
{

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= k; j++)
        {

            int result = 0;

            for (int inv = 0; inv <= min(i - 1, j); inv++)
            {
                result = (result + dp[i - 1][j - inv]) % mod;
            }

            dp[i][j] = result;
        }
    }

    return dp[n][k];
}

int optimized(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        long long sum = 1;
        for (int j = 1; j <= k; j++)
        {
            sum += dp[i - 1][j];
            if (j >= i)
            {
                sum -= dp[i - 1][j - i];
            }

            dp[i][j] = sum % mod;
        }
    }

    return dp[n][k];
}

int kInversePairs(int n, int k)
{
    // memset(dp, -1, sizeof(dp));

    // return solve(n, k);

    // return tablulation(n, k);

    return optimized(n, k);
}

int main()
{

    int n = 3, k = 1;

    cout << kInversePairs(n, k) << endl;

    return 0;
}