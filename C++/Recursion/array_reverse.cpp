#include <bits/stdc++.h>

using namespace std;

void reverseArray(int *arr, int &startIndex, int &n)
{

    if (startIndex >= n / 2)
        return;

    swap(arr[startIndex++], arr[n - 1 - startIndex]);

    reverseArray(arr, startIndex, n);
}

int main()
{

    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    cout << endl
         << endl;
    int i = 0;

    reverseArray(arr, i, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}