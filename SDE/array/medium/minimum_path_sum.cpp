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
int sum = 0;
int calculatePath(int row, int col, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
        return grid[row][col];
    if (row < 0 || col < 0)
        return 0;

    int upper = calculatePath(row - 1, col, grid);
    int left = calculatePath(row, col - 1, grid);

    sum += max(upper, left);

    cout << sum << endl;

    return sum;
}

int minPathSum(vector<vector<int>> &grid)
{
    int row = grid.size() - 1;
    int col = grid[0].size() - 1;
    return calculatePath(row, col, grid);
}

int main()
{

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };

    print(grid);

    cout << minPathSum(grid) << endl;

    return 0;
}