#include <bits/stdc++.h>

using namespace std;

int largestElement(vector<int> &arr, int n)
{
    int maxValue = arr[0];

    for (int i = 0; i < n; i++)
        if (arr[i] > maxValue)
            maxValue = arr[i];

    return maxValue;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << largestElement(arr, n);

    return 0;
}