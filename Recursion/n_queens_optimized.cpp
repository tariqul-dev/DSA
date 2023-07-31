#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:
    void solve(vector<string> &board, vector<vector<string>> &result, vector<int> &leftRow, vector<int> &loweDiagonal, vector<int> &upperDialognal, int n, int col = 0)
    {
        if (col == n)
        {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 &&
                loweDiagonal[row + col] == 0 &&
                upperDialognal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                loweDiagonal[row + col] = 1;
                upperDialognal[n - 1 + col - row] = 1;

                solve(board, result, leftRow, loweDiagonal, upperDialognal, n, col + 1);

                board[row][col] = '.';
                leftRow[row] = 0;
                loweDiagonal[row + col] = 0;
                upperDialognal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n, '.');
        vector<int> lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0), leftRow(n, 0);

        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(board, result, leftRow, lowerDiagonal, upperDiagonal, n);

        return result;
    }
};

int main()
{
    int n = 4;
    vector<vector<string>> result = Solution().solveNQueens(n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << endl;
        }

        cout << endl
             << endl;
    }

    return 0;
}