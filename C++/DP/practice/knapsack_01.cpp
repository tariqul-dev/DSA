#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int m, vector<int> &p, vector<int> &wt)
{
    int k[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
            }
            else if (wt[i] <= w)
            {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << k[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int i = n, j = m;

    while (i > 0 && j > 0)
    {

        cout << "i:  " << i << endl;
        if (k[i][j] == k[i - 1][j])
        {
            cout << i << " = 0" << endl;
            i--;
        }
        else
        {
            cout << i << " = 1" << endl;
            j = j - wt[i];
            i--;
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    vector<int> wt(n + 1);

    p.push_back(0);
    wt.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> wt[i];
    }

    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << p[i] << " " << wt[i] << endl;
    }

    cout << endl;

    cout << knapsack(n, m, p, wt) << endl;

    return 0;
}

/*
4 8
1 2
2 3
5 4
6 5
*/