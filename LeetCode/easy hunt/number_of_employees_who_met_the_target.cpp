#include <bits/stdc++.h>

using namespace std;

int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
{
    int count = 0;
    for (int hour : hours)
        if (hour >= target)
            count++;

    return count;
}

int main()
{

    vector<int> hours = {0, 1, 2, 3, 4};
    int target = 2;

    cout << numberOfEmployeesWhoMetTarget(hours, target) << endl;

    return 0;
}
