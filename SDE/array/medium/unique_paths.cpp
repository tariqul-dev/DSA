#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> grid)
{

    for (auto g : grid)
    {
        for (int i : g)
            cout << i << " ";
        cout << endl;
    }
}

void print(vector<int> grid)
{

    for (auto g : grid)
        cout << g << " ";
    cout << endl;
}

int countPaths(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;

    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int upper = countPaths(m - 1, n, dp);
    int left = countPaths(m, n - 1, dp);

    return dp[m][n] = upper + left;
}

int countPathsTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
                dp[0][0] = 1;
            else
            {

                int upper = 0;
                int left = 0;

                if (row > 0)
                    upper = dp[row - 1][col];

                if (col > 0)
                    left = dp[row][col - 1];

                dp[row][col] = upper + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

int countPathsSpaceOp(int m, int n)
{
    vector<int> prev(n, 0);

    for (int row = 0; row < m; row++)
    {
        vector<int> current(n, 0);

        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
                current[col] = 1;
            else
            {
                int up = 0;
                int left = 0;

                if (row > 0)
                    up = prev[col];
                if (col > 0)
                    left = current[col - 1];

                current[col] = up + left;
            }
        }

        prev = current;
    }
    return prev[n - 1];
}

int uniquePaths(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, -1));

    // return countPaths(m - 1, n - 1, dp);

    return countPathsSpaceOp(m, n);
}

int main()
{

    int m = 3, n = 7;

    cout << uniquePaths(m, n) << endl;

    return 0;
}