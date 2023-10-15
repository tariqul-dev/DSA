#include <bits/stdc++.h>

using namespace std;

int isSorted(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;

    return true;
}

int main()
{
    int n = 1;

    vector<int> a = {1};

    cout << isSorted(n, a) << endl;

    return 0;
}