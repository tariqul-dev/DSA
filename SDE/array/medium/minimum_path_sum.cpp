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

int calculatePath(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return grid[0][0];

    if (row < 0 || col < 0)
        return 99999;

    if (dp[row][col] != -1)
        return dp[row][col];

    int upper = grid[row][col] + calculatePath(row - 1, col, grid, dp);
    int left = grid[row][col] + calculatePath(row, col - 1, grid, dp);

    return dp[row][col] = min(upper, left);
}

int calculatePathTabulation(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    int inf = 1e9;

    int m = grid.size();
    int n = grid[0].size();

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                dp[row][col] = grid[row][col];
            }
            else
            {
                int upper = grid[row][col];
                if (row > 0)
                    upper += dp[row - 1][col];
                else
                    upper += inf;

                int left = grid[row][col];
                if (col > 0)
                    left += dp[row][col - 1];
                else
                    left += inf;

                dp[row][col] = min(upper, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}

int calculatePathOptimize(vector<vector<int>> &grid)
{
    vector<int> prev(grid[0].size(), 0);

    int inf = 1e9;

    int m = grid.size();
    int n = grid[0].size();

    for (int row = 0; row < m; row++)
    {
        vector<int> current(n, 0);

        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
                current[col] = grid[row][col];

            else
            {
                int upper = grid[row][col];
                if (row > 0)
                    upper += prev[col];
                else
                    upper += inf;

                int left = grid[row][col];
                if (col > 0)
                    left += current[col - 1];
                else
                    left += inf;

                current[col] = min(upper, left);
            }
        }
        prev = current;
    }

    return prev[n - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    // int row = grid.size() - 1;
    // int col = grid[0].size() - 1;

    // vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));

    // return calculatePath(row, col, grid, dp);

    // return calculatePathTabulation(grid);
    return calculatePathOptimize(grid);
}

int main()
{

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };

    print(grid);
    cout << endl;

    cout << minPathSum(grid) << endl;

    return 0;
}