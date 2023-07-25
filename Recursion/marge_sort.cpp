#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int i = 0)
{
    if (i >= arr.size())
        return;

    cout << arr[i] << " ";

    print(arr, i + 1);
}

void divide(vector<int> &arr, vector<int> output, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        cout << arr[startIndex] << " ";
        cout << "single " << endl;
        return;
    }

    int mid = (startIndex + endIndex) / 2;

    // for (int i = startIndex; i < mid; i++)
    // {
    //     output.push_back(arr[i]);
    // }

    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "low " << endl;

    divide(arr, output, startIndex, mid);

    // for (int i = startIndex; i <= endIndex; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << "single " << endl;

    divide(arr, output, mid + 1, endIndex);

    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "high " << endl;
}

int main()
{

    vector<int> arr = {5, 2, 1, 7, 10};

    print(arr);

    cout << endl
         << endl;

    divide(arr, vector<int>(), 0, arr.size() - 1);

    cout << endl;

    return 0;
}