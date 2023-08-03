#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int righ = mid + 1;

    while (left <= mid && righ <= high)
        if (arr[left] < arr[righ])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[righ++]);

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (righ <= high)
        temp.push_back(arr[righ++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        cout << "AT NOW: " << arr[low] << endl;
        return;
    }

    int mid = (low + high) / 2;

    cout << "before: ";
    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, low, mid);

    cout << "Inside: ";
    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, mid + 1, high);

    cout << "After: ";
    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    merge(arr, low, mid, high);
}

int main()
{

    vector<int> arr = {4, 6, 3, 2, 1, 5};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Final sorted: ";

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}