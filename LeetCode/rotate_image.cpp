#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> &matrix)
{
    for (auto ele : matrix)
    {
        for (auto d : ele)
            cout << d << " ";
        cout << endl;
    }
}

void rotate(vector<vector<int>> &matrix)
{
    reverse(matrix.begin(), matrix.end());

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(matrix);

    print(matrix);

    return 0;
}