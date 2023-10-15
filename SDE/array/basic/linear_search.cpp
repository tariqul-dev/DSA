#include <bits/stdc++.h>

using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == num)
            return i;

    return -1;
}

int main()
{
    int n = 5, num = 4;
    vector<int> arr = {6, 7, 8, 4, 1};

    cout << linearSearch(n, num, arr) << endl;

    return 0;
}