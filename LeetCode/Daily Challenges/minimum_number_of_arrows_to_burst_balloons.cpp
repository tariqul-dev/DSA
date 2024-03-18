#include <bits/stdc++.h>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    int n = points.size();

    sort(points.begin(), points.end());

    vector<int> prev = points[0];

    int arrowCount = 1;

    for (int i = 1; i < n; i++)
    {
        int currentStartPoint = points[i][0];
        int currentEndPoint = points[i][1];

        int preStartPoint = prev[0];
        int preEndPoint = prev[1];

        if (currentStartPoint > preEndPoint)
        {                     // Non overlaping condition
            arrowCount++;     // use another arrow
            prev = points[i]; // make current balloone as previous
        }
        else
        { // Overlapping Condition. Calculating Overlaping region
            prev[0] = max(currentStartPoint, preStartPoint);
            prev[1] = min(currentEndPoint, preEndPoint);
        }
    }

    return arrowCount;
}

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    cout << findMinArrowShots(points) << endl;

    return 0;
}