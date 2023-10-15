#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int a : arr)
        cout << a << " ";
    cout << endl;
}

vector<int> rotateArray(vector<int> &arr, int n)
{
    // vector<int> temp(n);

    // for (int i = 0; i < n; i++)
    // {
    //     temp[abs((i - 1) % n)] = arr[i];
    // }

    // temp[n - 1] = arr[0];

    // arr = temp;

    // return arr;

    // optimal
    int firstElement = arr[0];

    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    arr[n - 1] = firstElement;

    return arr;
}

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << -9 % 5 << endl;

    print(rotateArray(arr, n));

    return 0;
}