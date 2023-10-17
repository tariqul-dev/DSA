#include <bits/stdc++.h>

using namespace std;

/*
row = index / m
col = index % m
*/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = (m * n) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;

        if (matrix[row][col] == target)
            return true;

        else if (target < matrix[row][col])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
    };
    int target = 12;

    cout << searchMatrix(matrix, target);

    return 0;
}