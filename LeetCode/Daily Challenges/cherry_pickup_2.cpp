#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    {
        return -1e8;
    }

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxValue = -1e8;

    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;

            if (j1 == j2)
            {
                value = grid[i][j1];
            }
            else
            {
                value = grid[i][j1] + grid[i][j2];
            }

            value += solve(i + 1, j1 + dj1, j2 + dj2, m, n, grid, dp);

            maxValue = max(maxValue, value);
        }
    }

    return dp[i][j1][j2] = maxValue;
}

// Tabulation
int tabulation(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // base case

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int result = -1e8;

                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {

                        int val = 0;

                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];

                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];

                        else
                            val += -1e8;

                        result = max(val, result);
                    }
                }

                dp[i][j1][j2] = result;
            }
        }
    }

    return dp[0][0][m - 1];

    // return solve(0, 0, m - 1, n, m, grid, dp);
}

int cherryPickup(vector<vector<int>> &grid)
{
    // int n = grid.size();
    // int m = grid[0].size();

    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // return solve(0, 0, m - 1, m, n, grid, dp);

    return tabulation(grid);
}

int main()
{

    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    cout << cherryPickup(grid) << endl;

    return 0;
}