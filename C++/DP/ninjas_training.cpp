#include <bits/stdc++.h>

using namespace std;

const int numberOfTask = 3;

int getMerit(int day, int last, vector<vector<int>> &tasks)
{
    if (day == 0)
    {
        int merit = 0;
        for (int i = 0; i < numberOfTask; i++)
        {
            if (last != i)
                merit = max(merit, tasks[day][i]);
        }
        return merit;
    }

    int merit = 0;
    for (int i = 0; i < numberOfTask; i++)
    {
        if (last != i)
        {
            int point = tasks[day][i] + getMerit(day - 1, i, tasks);
            merit = max(merit, point);
        }
    }

    return merit;
}

int getMeritMemoization(int day, int last, vector<vector<int>> &tasks, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int merit = 0;

        for (int i = 0; i < numberOfTask; i++)
        {
            if (last != i)
            {
                merit = max(merit, tasks[day][i]);
            }
        }
        return merit;
    }
    if (dp[day][last] != -1)
        return dp[day][last];

    int merit = 0;
    for (int i = 0; i < numberOfTask; i++)
    {
        if (last != i)
        {
            int point = tasks[day][i] + getMeritMemoization(day - 1, i, tasks, dp);
            merit = max(merit, point);
        }
    }

    dp[day][last] = merit;
    return merit;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // return getMerit(n - 1, 3, points);
    vector<vector<int>> dp(n, vector<int>(numberOfTask + 1, -1));
    return getMeritMemoization(n - 1, 3, points, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int day;
        cin >> day;

        vector<vector<int>> tasks(day, vector<int>(numberOfTask));

        for (int i = 0; i < day; i++)
        {
            for (int j = 0; j < numberOfTask; j++)
            {
                cin >> tasks[i][j];
            }
        }
        cout << endl;

        for (int i = 0; i < day; i++)
        {
            for (int j = 0; j < numberOfTask; j++)
            {
                cout << tasks[i][j] << " ";
            }
            cout << endl;
        }

        cout << ninjaTraining(day, tasks) << endl;
    }

    return 0;
}

/*
Sample Input 1:
2
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90

Sample Output 1:
11
210


Sample Input 2:
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11

Sample Output 2:
45
110

*/