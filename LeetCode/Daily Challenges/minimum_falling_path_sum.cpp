#include <bits/stdc++.h>

using namespace std;

int calculateMinPath(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= matrix[0].size())
        return 1e5;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != 1e5)
    {
        return dp[i][j];
    }

    int up = matrix[i][j] + calculateMinPath(i - 1, j, matrix, dp);
    int leftDiagonal = matrix[i][j] + calculateMinPath(i - 1, j - 1, matrix, dp);
    int rightDiagonal = matrix[i][j] + calculateMinPath(i - 1, j + 1, matrix, dp);

    return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
}

int calculateMinPathTabulation(vector<vector<int>> &matrix)
{
    int n = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = 1e5;
            if (j - 1 >= 0)
            {
                leftDiagonal = matrix[i][j] + dp[i - 1][j - 1];
            }

            int rightDiagonal = 1e5;
            if (j + 1 < n)
            {
                rightDiagonal = matrix[i][j] + dp[i - 1][j + 1];
            }

            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    int minValue = dp[n - 1][0];
    for (int j = 1; j < n; j++)
    {
        minValue = min(minValue, dp[n - 1][j]);
    }

    return minValue;
}

int calculateMinPathSpaceOptimized(vector<vector<int>> &matrix)
{
    int n = matrix[0].size();
    vector<int> prev(n), current(n);

    for (int j = 0; j < n; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = matrix[i][j] + prev[j];
            int leftDiagonal = 1e5;
            if (j - 1 >= 0)
            {
                leftDiagonal = matrix[i][j] + prev[j - 1];
            }

            int rightDiagonal = 1e5;
            if (j + 1 < n)
            {
                rightDiagonal = matrix[i][j] + prev[j + 1];
            }

            current[j] = min(up, min(leftDiagonal, rightDiagonal));
        }

        prev = current;
    }

    int minValue = prev[0];

    for (int j = 1; j < n; j++)
        minValue = min(minValue, prev[j]);

    return minValue;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{

    return calculateMinPathSpaceOptimized(matrix);

    // int n = matrix[0].size();
    // vector<vector<int>> dp(n, vector<int>(n, 1e5));

    // int minValue = 1e5;

    // for (int col = 0; col < n; col++)
    // {
    //     minValue = min(minValue, calculateMinPath(n - 1, col, matrix, dp));
    // }

    // return minValue;
}

int main()
{

    vector<vector<int>> matrix =
        {
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9},
        };

    cout << minFallingPathSum(matrix) << endl;

    return 0;
}