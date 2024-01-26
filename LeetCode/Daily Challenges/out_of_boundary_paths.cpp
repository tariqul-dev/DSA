#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dp[51][51][51];

int solve(int m, int n, int maxMove, int startRow, int startColumn)
{
    if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
    {
        return 1;
    }

    if (maxMove <= 0)
        return 0;

    if (dp[startRow][startColumn][maxMove] != -1)
        return dp[startRow][startColumn][maxMove];

    int result = 0;
    for (vector<int> &dir : directions)
    {
        int newRow = startRow + dir[0];
        int newCol = startColumn + dir[1];

        result = (result + solve(m, n, maxMove - 1, newRow, newCol)) % MOD;
    }

    return dp[startRow][startColumn][maxMove] = result;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    memset(dp, -1, sizeof(dp));

    return solve(m, n, maxMove, startRow, startColumn);
}

int main()
{

    int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;

    cout
        << findPaths(m, n, maxMove, startRow, startColumn) << endl;

    return 0;
}