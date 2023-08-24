#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int i = 0)
{
    if (i == arr.size())
        return;

    cout << arr[i] << " ";
    print(arr, i + 1);
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {6, 4, 2, 7, 5, 3};

    print(arr);
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    print(arr);
    cout << endl;

    return 0;
}