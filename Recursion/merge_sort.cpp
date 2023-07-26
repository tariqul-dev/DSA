#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int startIndex, int length)
{
    if (startIndex == length)
        return;

    cout << arr[startIndex++] << " ";
    print(arr, startIndex, length);
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

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

    // vector<int> arr = {5, 2, 1, 5, 7, 10};
    vector<int> arr = {10, 7, 5, 5, 2, 1};
    print(arr, 0, arr.size());

    mergeSort(arr, 0, arr.size() - 1);
    cout << endl;

    print(arr, 0, arr.size());

    return 0;
}