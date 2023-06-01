#include <bits/stdc++.h>

using namespace std;

int sum(int n, int arr[])
{
    if (n < 0)
        return 0;

    return sum(n - 1, arr) + arr[n];
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5};

    cout << sum(n - 1, arr);

    return 0;
}