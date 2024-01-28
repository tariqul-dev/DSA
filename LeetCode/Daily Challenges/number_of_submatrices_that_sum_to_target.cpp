#include <bits/stdc++.h>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{
    int totalRow = matrix.size();
    int totalColumn = matrix[0].size();

    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 1; col < totalColumn; col++)
        {
            matrix[row][col] += matrix[row][col - 1];
        }
    }

    int result = 0;

    for (int startColumn = 0; startColumn < totalColumn; startColumn++)
    {
        for (int j = startColumn; j < totalColumn; j++)
        {
            unordered_map<int, int> mp;

            mp.insert({0, 1});
            int sum = 0;

            for (int row = 0; row < totalRow; row++)
            {
                sum += matrix[row][j];
                if (startColumn > 0)
                    sum -= matrix[row][startColumn - 1];

                int remain = sum - target;

                if (mp.find(remain) != mp.end())
                {
                    result += mp[remain];
                }

                mp[sum]++;
            }
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> matrix = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    int target = 0;

    cout << numSubmatrixSumTarget(matrix, target) << endl;

    return 0;
}