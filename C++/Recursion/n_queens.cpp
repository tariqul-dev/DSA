#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        int rowCopy = row;
        int colCopy = col;

        // upper diagonal checking
        while (rowCopy >= 0 && colCopy >= 0)
        {
            if (board[rowCopy][colCopy] == 'Q')
                return false;

            rowCopy--;
            colCopy--;
        }

        rowCopy = row;
        colCopy = col;
        // previous colums checking
        while (colCopy >= 0)
        {
            if (board[rowCopy][colCopy] == 'Q')
                return false;
            colCopy--;
        }

        rowCopy = row;
        colCopy = col;
        // lower diagonal checking
        while (rowCopy < n && colCopy >= 0)
        {
            if (board[rowCopy][colCopy] == 'Q')
                return false;
            colCopy--;
            rowCopy++;
        }

        // if it is possible to place a queen in board
        return true;
    }

    void solve(vector<string> &board, vector<vector<string>> &result, int n, int col = 0)
    {
        if (col == n)
        {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(board, result, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(board, result, n);

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