#include <bits/stdc++.h>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int maxCount = 0;

    for (auto account : accounts)
    {
        int count = 0;
        for (auto w : account)
        {
            count += w;
        }

        if (count > maxCount)
            maxCount = count;
    }

    return maxCount;
}

int main()
{
    vector<vector<int>> accounts = {{1, 5}, {7, 3}, {3, 5}};

    cout << maximumWealth(accounts) << endl;

    return 0;
}