#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> directions = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

bool find(vector<vector<char>> &board, int row, int col, int m, int n, int index, string &word)
{
    if (index == word.length())
        return true;

    if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '$')
        return false;

    if (board[row][col] != word[index])
        return false;

    char temp = board[row][col];
    board[row][col] = '$';

    for (auto &dir : directions)
    {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        if (find(board, newRow, newCol, m, n, index + 1, word))
            return true;
    }

    board[row][col] = temp;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0] && find(board, i, j, m, n, 0, word))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    cout << exist(board, word) << endl;

    return 0;
}